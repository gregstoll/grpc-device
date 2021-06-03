#include <nidaqmx/nidaqmx_service.h>

namespace nidaqmx_grpc {

::grpc::Status NiDAQmxService::ReadAnalogF64StreamCustom(::grpc::ServerContext* context, const ReadAnalogF64StreamCustomRequest* request, ::grpc::ServerWriter<ReadAnalogF64StreamCustomResponse>* writer)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ReadAnalogF64StreamCustomResponse localResponse;
    auto response = &localResponse;
    auto task_grpc_session = request->task();
    auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
    int32 num_samps_per_chan = request->num_samps_per_chan();
    double timeout = request->timeout();
    int32 fill_mode = request->fill_mode();
    uInt32 array_size_in_samps = request->array_size_in_samps();
    uInt64 reserved = request->reserved();
    response->mutable_read_array()->Resize(array_size_in_samps, 0);
    float64* read_array = response->mutable_read_array()->mutable_data();
    int32 samps_per_chan{};
    int32 status = 0;
    do {
      // Note: calls the callback from vanilla read: important that that exists!
      status = library_->ReadAnalogF64(task, num_samps_per_chan, timeout, fill_mode, read_array, array_size_in_samps, &samps_per_chan, reserved);
      response->set_status(status);
      if (status == 0) {
        response->set_samps_per_chan(samps_per_chan);
      }
    } while (writer->Write(localResponse) && !status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDAQmxService::WriteAnalogF64StreamCustom(::grpc::ServerContext* context, ::grpc::ServerReader<WriteAnalogF64StreamCustomRequest>* reader, WriteAnalogF64StreamCustomResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    WriteAnalogF64StreamCustomRequest local_request;
    auto request = &local_request;
    while (reader->Read(request)) {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      int32 num_samps_per_chan = request->num_samps_per_chan();
      int32 auto_start = request->auto_start();
      double timeout = request->timeout();
      int32 data_layout = request->data_layout();
      auto write_array = request->write_array().data();
      uInt64 reserved = request->reserved();
      int32 samps_per_chan_written{};
      auto status = library_->WriteAnalogF64(task, num_samps_per_chan, auto_start, timeout, data_layout, write_array, &samps_per_chan_written, reserved);
      response->set_status(status);
      if (status == 0) {
        response->set_samps_per_chan_written(samps_per_chan_written);
      }
      else {
        break;
      }
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

  //---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiDAQmxService::WriteDigitalU32Stream(::grpc::ServerContext* context, ::grpc::ServerReader<WriteDigitalU32StreamRequest>* reader, WriteDigitalU32StreamResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    WriteDigitalU32StreamRequest local_request;
    auto request = &local_request;
    while (reader->Read(request)) {
      auto task_grpc_session = request->task();
      auto task = session_repository_.access_session(task_grpc_session.id(), task_grpc_session.name());
      int32 num_samps_per_chan = request->num_samps_per_chan();
      int32 auto_start = request->auto_start();
      double timeout = request->timeout();
      int32 data_layout = request->data_layout();
      auto write_array = reinterpret_cast<const uInt32*>(request->write_array().data());
      uInt64 reserved = request->reserved();
      int32 samps_per_chan_written{};
      auto status = library_->WriteDigitalU32Stream(task, num_samps_per_chan, auto_start, timeout, data_layout, write_array, &samps_per_chan_written, reserved);
      response->set_status(status);
      if (status == 0) {
        response->set_samps_per_chan_written(samps_per_chan_written);
      }
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace nidaqmx_grpc