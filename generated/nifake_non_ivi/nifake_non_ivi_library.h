//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-FAKE-NON-IVI
//---------------------------------------------------------------------
#ifndef NIFAKE_NON_IVI_GRPC_LIBRARY_H
#define NIFAKE_NON_IVI_GRPC_LIBRARY_H

#include "nifake_non_ivi_library_interface.h"

#include <server/shared_library.h>

namespace nifake_non_ivi_grpc {

class NiFakeNonIviLibrary : public nifake_non_ivi_grpc::NiFakeNonIviLibraryInterface {
 public:
  NiFakeNonIviLibrary();
  virtual ~NiFakeNonIviLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  int32 Close(FakeHandle handle);
  int32 Init(const char* sessionName, FakeHandle* handle);
  int32 InitWithHandleNameAsSessionName(const char* handleName, FakeHandle* handle);

 private:
  using ClosePtr = int32 (*)(FakeHandle handle);
  using InitPtr = int32 (*)(const char* sessionName, FakeHandle* handle);
  using InitWithHandleNameAsSessionNamePtr = int32 (*)(const char* handleName, FakeHandle* handle);

  typedef struct FunctionPointers {
    ClosePtr Close;
    InitPtr Init;
    InitWithHandleNameAsSessionNamePtr InitWithHandleNameAsSessionName;
  } FunctionLoadStatus;

  nidevice_grpc::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nifake_non_ivi_grpc

#endif  // NIFAKE_NON_IVI_GRPC_LIBRARY_H
