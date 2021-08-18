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
  int32 GetMarbleAttributeDouble(FakeHandle handle, int32 attribute, double* value);
  int32 GetMarbleAttributeInt32(FakeHandle handle, int32 attribute, int32* value);
  int32 Init(const char sessionName[], FakeHandle* handle);
  int32 InitWithHandleNameAsSessionName(const char handleName[], FakeHandle* handle);
  int32 InputArraysWithNarrowIntegerTypes(const myUInt16 u16Array[], const myInt16 i16Array[], const myInt8 i8Array[]);
  int32 IotaWithCustomSize(int32 sizeOne, int32 sizeTwo, int32 data[]);
  int32 OutputArraysWithNarrowIntegerTypes(int32 numberOfU16Samples, myUInt16 u16Data[], int32 numberOfI16Samples, myInt16 i16Data[], int32 numberOfI8Samples, myInt8 i8Data[]);
  int32 InputArrayOfBytes(const myUInt8 u8Array[]);
  int32 OutputArrayOfBytes(int32 numberOfU8Samples, myUInt8 u8Data[]);
  int32 RegisterCallback(myInt16 inputData, CallbackPtr callbackFunction, void* callbackData);
  int32 ReadStream(int32 start, int32 stop, int32* value);
  int32 InputTimestamp(CVIAbsoluteTime when);
  int32 OutputTimestamp(CVIAbsoluteTime* when);
  int32 InputVarArgs(const char inputName[], const char channelName[], int32 color, double powerUpState, const char channelName0[], int32 color0, double powerUpState0, const char channelName1[], int32 color1, double powerUpState1, const char channelName2[], int32 color2, double powerUpState2);
  int32 OutputVarArgs(const char inputName[], const char channelName[], int32* color, const char channelName0[], int32* color0, const char channelName1[], int32* color1, const char channelName2[], int32* color2);
  int32 ResetMarbleAttribute(FakeHandle handle, int32 attribute);
  int32 SetMarbleAttributeDouble(FakeHandle handle, int32 attribute, double value);
  int32 SetMarbleAttributeInt32(FakeHandle handle, int32 attribute, int32 value);

 private:
  using ClosePtr = int32 (*)(FakeHandle handle);
  using GetMarbleAttributeDoublePtr = int32 (*)(FakeHandle handle, int32 attribute, double* value);
  using GetMarbleAttributeInt32Ptr = int32 (*)(FakeHandle handle, int32 attribute, int32* value);
  using InitPtr = int32 (*)(const char sessionName[], FakeHandle* handle);
  using InitWithHandleNameAsSessionNamePtr = int32 (*)(const char handleName[], FakeHandle* handle);
  using InputArraysWithNarrowIntegerTypesPtr = int32 (*)(const myUInt16 u16Array[], const myInt16 i16Array[], const myInt8 i8Array[]);
  using IotaWithCustomSizePtr = int32 (*)(int32 sizeOne, int32 sizeTwo, int32 data[]);
  using OutputArraysWithNarrowIntegerTypesPtr = int32 (*)(int32 numberOfU16Samples, myUInt16 u16Data[], int32 numberOfI16Samples, myInt16 i16Data[], int32 numberOfI8Samples, myInt8 i8Data[]);
  using InputArrayOfBytesPtr = int32 (*)(const myUInt8 u8Array[]);
  using OutputArrayOfBytesPtr = int32 (*)(int32 numberOfU8Samples, myUInt8 u8Data[]);
  using RegisterCallbackPtr = int32 (*)(myInt16 inputData, CallbackPtr callbackFunction, void* callbackData);
  using ReadStreamPtr = int32 (*)(int32 start, int32 stop, int32* value);
  using InputTimestampPtr = int32 (*)(CVIAbsoluteTime when);
  using OutputTimestampPtr = int32 (*)(CVIAbsoluteTime* when);
  using InputVarArgsPtr = int32 (*)(const char inputName[], const char channelName[], int32 color, double powerUpState, ...);
  using OutputVarArgsPtr = int32 (*)(const char inputName[], const char channelName[], int32* color, ...);
  using ResetMarbleAttributePtr = int32 (*)(FakeHandle handle, int32 attribute);
  using SetMarbleAttributeDoublePtr = int32 (*)(FakeHandle handle, int32 attribute, double value);
  using SetMarbleAttributeInt32Ptr = int32 (*)(FakeHandle handle, int32 attribute, int32 value);

  typedef struct FunctionPointers {
    ClosePtr Close;
    GetMarbleAttributeDoublePtr GetMarbleAttributeDouble;
    GetMarbleAttributeInt32Ptr GetMarbleAttributeInt32;
    InitPtr Init;
    InitWithHandleNameAsSessionNamePtr InitWithHandleNameAsSessionName;
    InputArraysWithNarrowIntegerTypesPtr InputArraysWithNarrowIntegerTypes;
    IotaWithCustomSizePtr IotaWithCustomSize;
    OutputArraysWithNarrowIntegerTypesPtr OutputArraysWithNarrowIntegerTypes;
    InputArrayOfBytesPtr InputArrayOfBytes;
    OutputArrayOfBytesPtr OutputArrayOfBytes;
    RegisterCallbackPtr RegisterCallback;
    ReadStreamPtr ReadStream;
    InputTimestampPtr InputTimestamp;
    OutputTimestampPtr OutputTimestamp;
    InputVarArgsPtr InputVarArgs;
    OutputVarArgsPtr OutputVarArgs;
    ResetMarbleAttributePtr ResetMarbleAttribute;
    SetMarbleAttributeDoublePtr SetMarbleAttributeDouble;
    SetMarbleAttributeInt32Ptr SetMarbleAttributeInt32;
  } FunctionLoadStatus;

  nidevice_grpc::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nifake_non_ivi_grpc

#endif  // NIFAKE_NON_IVI_GRPC_LIBRARY_H
