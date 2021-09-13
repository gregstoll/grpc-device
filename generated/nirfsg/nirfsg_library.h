//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-RFSG
//---------------------------------------------------------------------
#ifndef NIRFSG_GRPC_LIBRARY_H
#define NIRFSG_GRPC_LIBRARY_H

#include "nirfsg_library_interface.h"

#include <server/shared_library.h>

namespace nirfsg_grpc {

class NiRFSGLibrary : public nirfsg_grpc::NiRFSGLibraryInterface {
 public:
  NiRFSGLibrary();
  virtual ~NiRFSGLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  ViStatus Init(ViRsrc resourceName, ViBoolean idQuery, ViBoolean reset, ViSession* vi);
  ViStatus Close(ViSession vi);
  ViStatus InitWithOptions(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi);

 private:
  using InitPtr = decltype(&niRFSG_init);
  using ClosePtr = decltype(&niRFSG_close);
  using InitWithOptionsPtr = decltype(&niRFSG_InitWithOptions);

  typedef struct FunctionPointers {
    InitPtr Init;
    ClosePtr Close;
    InitWithOptionsPtr InitWithOptions;
  } FunctionLoadStatus;

  nidevice_grpc::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nirfsg_grpc

#endif  // NIRFSG_GRPC_LIBRARY_H
