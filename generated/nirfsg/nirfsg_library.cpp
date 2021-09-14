//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-RFSG Metadata
//---------------------------------------------------------------------
#include "nirfsg_library.h"

#if defined(_MSC_VER)
static const char* kLibraryName = "niRFSG_64.dll";
#else
static const char* kLibraryName = "libnirfsg.so";
#endif

namespace nirfsg_grpc {

NiRFSGLibrary::NiRFSGLibrary() : shared_library_(kLibraryName)
{
  shared_library_.load();
  bool loaded = shared_library_.is_loaded();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!loaded) {
    return;
  }
  function_pointers_.Init = reinterpret_cast<InitPtr>(shared_library_.get_function_pointer("niRFSG_init"));
  function_pointers_.Close = reinterpret_cast<ClosePtr>(shared_library_.get_function_pointer("niRFSG_close"));
  function_pointers_.InitWithOptions = reinterpret_cast<InitWithOptionsPtr>(shared_library_.get_function_pointer("niRFSG_InitWithOptions"));
  function_pointers_.ErrorMessage = reinterpret_cast<ErrorMessagePtr>(shared_library_.get_function_pointer("niRFSG_error_message"));
}

NiRFSGLibrary::~NiRFSGLibrary()
{
}

::grpc::Status NiRFSGLibrary::check_function_exists(std::string functionName)
{
  return shared_library_.function_exists(functionName.c_str())
    ? ::grpc::Status::OK
    : ::grpc::Status(::grpc::NOT_FOUND, "Could not find the function " + functionName);
}

ViStatus NiRFSGLibrary::Init(ViRsrc resourceName, ViBoolean idQuery, ViBoolean reset, ViSession* vi)
{
  if (!function_pointers_.Init) {
    throw nidevice_grpc::LibraryLoadException("Could not find niRFSG_init.");
  }
#if defined(_MSC_VER)
  return niRFSG_init(resourceName, idQuery, reset, vi);
#else
  return function_pointers_.Init(resourceName, idQuery, reset, vi);
#endif
}

ViStatus NiRFSGLibrary::Close(ViSession vi)
{
  if (!function_pointers_.Close) {
    throw nidevice_grpc::LibraryLoadException("Could not find niRFSG_close.");
  }
#if defined(_MSC_VER)
  return niRFSG_close(vi);
#else
  return function_pointers_.Close(vi);
#endif
}

ViStatus NiRFSGLibrary::InitWithOptions(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi)
{
  if (!function_pointers_.InitWithOptions) {
    throw nidevice_grpc::LibraryLoadException("Could not find niRFSG_InitWithOptions.");
  }
#if defined(_MSC_VER)
  return niRFSG_InitWithOptions(resourceName, idQuery, resetDevice, optionString, vi);
#else
  return function_pointers_.InitWithOptions(resourceName, idQuery, resetDevice, optionString, vi);
#endif
}

ViStatus NiRFSGLibrary::ErrorMessage(ViSession vi, ViStatus errorCode, ViChar errorMessage[256])
{
  if (!function_pointers_.ErrorMessage) {
    throw nidevice_grpc::LibraryLoadException("Could not find niRFSG_error_message.");
  }
#if defined(_MSC_VER)
  return niRFSG_error_message(vi, errorCode, errorMessage);
#else
  return function_pointers_.ErrorMessage(vi, errorCode, errorMessage);
#endif
}

}  // namespace nirfsg_grpc
