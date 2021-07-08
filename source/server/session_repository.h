#ifndef NIDEVICE_GRPC_SESSION_REPOSITORY
#define NIDEVICE_GRPC_SESSION_REPOSITORY

#include <grpcpp/grpcpp.h>
#include <session.grpc.pb.h>

#include <atomic>
#include <shared_mutex>

#include "semaphore.h"

namespace nidevice_grpc {

class SessionRepository {
 public:
  SessionRepository();

  typedef std::function<int32_t()> InitFunc;
  typedef std::function<void(uint32_t)> CleanupSessionFunc;

  int add_session(const std::string& session_name, InitFunc init_func, CleanupSessionFunc cleanup_func, uint32_t& session_id);
  uint32_t access_session(uint32_t session_id, const std::string& session_name);
  void remove_session(uint32_t id);

  bool reserve(
      const ::grpc::ServerContext* context,
      const std::string& reservation_id,
      const std::string& client_id,
      ::grpc::Status& status);
  bool is_reserved_by_client(const std::string& reservation_id, const std::string& client_id);
  bool unreserve(const std::string& reservation_id, const std::string& client_id);
  bool reset_server();
  uint32_t next_id() { return ++_next_id; }

 private:
  struct ReservationInfo {
    std::string client_id;
    std::unique_ptr<Semaphore> lock;
    std::chrono::steady_clock::time_point creation_time;
    // The number of clients that have asked to reserve this reservation, but have not yet acquired the lock.
    int client_count;
  };

  struct SessionInfo {
    uint32_t id;
    std::string name;
    std::chrono::steady_clock::time_point last_access_time;
    SessionRepository::CleanupSessionFunc cleanup_func;
  };

  using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
  using SessionMap = std::map<uint32_t, std::shared_ptr<SessionInfo>>;
  using ReservationMap = std::map<std::string, std::shared_ptr<ReservationInfo>>;

  std::shared_ptr<ReservationInfo> find_or_create_reservation(const std::string& reservation_id, const std::string& client_id);
  void clear_reservations();
  bool close_sessions();
  void cleanup_session(const std::shared_ptr<SessionInfo>& session_info);
  bool release_reservation(const ReservationInfo* reservation_info);

  std::shared_mutex repository_lock_;
  // This map contains every session, including both named and unnamed ones.
  SessionMap sessions_;
  // These entries point at SessionInfo objects that are also contained in sessions_.
  NamedSessionMap named_sessions_;
  ReservationMap reservations_;
  std::atomic<uint32_t> _next_id;
};

template <typename TResourceHandle>
class ResourceRepository {
 public:
  typedef std::function<std::tuple<int, TResourceHandle>()> InitFunc;
  typedef std::function<void(TResourceHandle)> CleanupSessionFunc;

  ResourceRepository(SessionRepository* session_repository)
      : _session_repository(session_repository)
  {
  }

  int add_session(
      const std::string& session_name,
      InitFunc init_func,
      CleanupSessionFunc cleanup_func,
      uint32_t& session_id)
  {
    return _session_repository->add_session(
        session_name,
        [&]() -> std::tuple<int, uint32_t> {
          auto init_result = init_func();
          if (auto status = std::get<0>(init_result)) {
            return std::make_tuple(status, 0);
          }
          auto handle = std::get<1>(init_result);
          auto id = _session_repository->next_id();
          _map[id] = handle;
          _reverseMap[handle] = id;
          return std::make_tuple(0, id);
        },
        // By val capture to keep cleanup_func in memory.
        [=](uint32_t id) {
          auto handle = _map[id];
          return cleanup_func(handle);
        },
        session_id);
  }

  TResourceHandle access_session(uint32_t session_id, const std::string& session_name)
  {
    auto id = _session_repository->access_session(session_id, session_name);
    return _map[id];
  }

  void remove_session(TResourceHandle handle)
  {
    auto id = _reverseMap[handle];
    _session_repository->remove_session(id);
  }

 private:
  using SessionToResourceMap = std::map<uint32_t, TResourceHandle>;
  using ResourceToSessionMap = std::map<TResourceHandle, uint32_t>;

  SessionToResourceMap _map;
  ResourceToSessionMap _reverseMap;

  SessionRepository* _session_repository;
};
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SESSION_REPOSITORY
