//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-DAQMX
//---------------------------------------------------------------------
#ifndef NIDAQMX_GRPC_LIBRARY_H
#define NIDAQMX_GRPC_LIBRARY_H

#include "nidaqmx_library_interface.h"

#include <server/shared_library.h>

namespace nidaqmx_grpc {

class NiDAQmxLibrary : public nidaqmx_grpc::NiDAQmxLibraryInterface {
 public:
  NiDAQmxLibrary();
  virtual ~NiDAQmxLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  int32 CreateTask(const char* taskName, TaskHandle* task);
  int32 ClearTask(TaskHandle task);
  int32 StartTask(TaskHandle task);
  int32 StopTask(TaskHandle task);
  int32 ExportSignal(TaskHandle task, int32 signal_id, const char* output_terminal);
  int32 GetExtendedErrorInfo(char error_string[], int32 buffer_size);
  int32 ConnectTerms(const char* source_terminal, const char* destination_terminal);
  int32 DisconnectTerms(const char* source_terminal, const char* destination_terminal);
  int32 CfgDigEdgeStartTrig(TaskHandle task, const char* trigger_source, int32 trigger_edge);
  int32 CreateAIVoltageChan(TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, int32 terminal_config, double min_val, double max_val, int32 units, const char* custom_scale_name);
  int32 CreateAOVoltageChan(TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, double min_val, double max_val, int32 units, const char* custom_scale_name);
  int32 CreateDIChan(TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping);
  int32 CreateDOChan(TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping);
  int32 GetChanAttributeU32(TaskHandle task, const char* channel, int32 attribute, uInt32* value);
  int32 SetChanAttributeU32(TaskHandle task, const char* channel, int32 attribute, uInt32 value);
  int32 GetChanAttributeF64(TaskHandle task, const char* channel, int32 attribute, double* value);
  int32 SetChanAttributeF64(TaskHandle task, const char* channel, int32 attribute, double value);
  int32 GetChanAttributeStr(TaskHandle task, const char* channel, int32 attribute, char value[], int32 size);
  int32 SetChanAttributeStr(TaskHandle task, const char* channel, int32 attribute, const char* value);
  int32 ReadDigitalU32(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  int32 ReadDigitalU32Stream(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  int32 WriteDigitalU32(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  int32 WriteDigitalU32Stream(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  int32 ReadAnalogF64(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  int32 ReadAnalogF64StreamCodegen(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  int32 ReadAnalogF64StreamCustom(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  int32 WriteAnalogF64(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  int32 WriteAnalogF64StreamCustom(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  int32 CfgSampClkTiming(TaskHandle task, const char* source, double rate, int32 active_edge, int32 sample_mode, uInt64 samps_per_chan);

 private:
  using CreateTaskPtr = int32 (*)(const char* taskName, TaskHandle* task);
  using ClearTaskPtr = int32 (*)(TaskHandle task);
  using StartTaskPtr = int32 (*)(TaskHandle task);
  using StopTaskPtr = int32 (*)(TaskHandle task);
  using ExportSignalPtr = int32 (*)(TaskHandle task, int32 signal_id, const char* output_terminal);
  using GetExtendedErrorInfoPtr = int32 (*)(char error_string[], int32 buffer_size);
  using ConnectTermsPtr = int32 (*)(const char* source_terminal, const char* destination_terminal);
  using DisconnectTermsPtr = int32 (*)(const char* source_terminal, const char* destination_terminal);
  using CfgDigEdgeStartTrigPtr = int32 (*)(TaskHandle task, const char* trigger_source, int32 trigger_edge);
  using CreateAIVoltageChanPtr = int32 (*)(TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, int32 terminal_config, double min_val, double max_val, int32 units, const char* custom_scale_name);
  using CreateAOVoltageChanPtr = int32 (*)(TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, double min_val, double max_val, int32 units, const char* custom_scale_name);
  using CreateDIChanPtr = int32 (*)(TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping);
  using CreateDOChanPtr = int32 (*)(TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping);
  using GetChanAttributeU32Ptr = int32 (*)(TaskHandle task, const char* channel, int32 attribute, uInt32* value);
  using SetChanAttributeU32Ptr = int32 (*)(TaskHandle task, const char* channel, int32 attribute, uInt32 value);
  using GetChanAttributeF64Ptr = int32 (*)(TaskHandle task, const char* channel, int32 attribute, double* value);
  using SetChanAttributeF64Ptr = int32 (*)(TaskHandle task, const char* channel, int32 attribute, double value);
  using GetChanAttributeStrPtr = int32 (*)(TaskHandle task, const char* channel, int32 attribute, char value[], int32 size);
  using SetChanAttributeStrPtr = int32 (*)(TaskHandle task, const char* channel, int32 attribute, const char* value);
  using ReadDigitalU32Ptr = int32 (*)(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  using ReadDigitalU32StreamPtr = int32 (*)(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  using WriteDigitalU32Ptr = int32 (*)(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  using WriteDigitalU32StreamPtr = int32 (*)(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  using ReadAnalogF64Ptr = int32 (*)(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  using ReadAnalogF64StreamCodegenPtr = int32 (*)(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  using ReadAnalogF64StreamCustomPtr = int32 (*)(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved);
  using WriteAnalogF64Ptr = int32 (*)(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  using WriteAnalogF64StreamCustomPtr = int32 (*)(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved);
  using CfgSampClkTimingPtr = int32 (*)(TaskHandle task, const char* source, double rate, int32 active_edge, int32 sample_mode, uInt64 samps_per_chan);

  typedef struct FunctionPointers {
    CreateTaskPtr CreateTask;
    ClearTaskPtr ClearTask;
    StartTaskPtr StartTask;
    StopTaskPtr StopTask;
    ExportSignalPtr ExportSignal;
    GetExtendedErrorInfoPtr GetExtendedErrorInfo;
    ConnectTermsPtr ConnectTerms;
    DisconnectTermsPtr DisconnectTerms;
    CfgDigEdgeStartTrigPtr CfgDigEdgeStartTrig;
    CreateAIVoltageChanPtr CreateAIVoltageChan;
    CreateAOVoltageChanPtr CreateAOVoltageChan;
    CreateDIChanPtr CreateDIChan;
    CreateDOChanPtr CreateDOChan;
    GetChanAttributeU32Ptr GetChanAttributeU32;
    SetChanAttributeU32Ptr SetChanAttributeU32;
    GetChanAttributeF64Ptr GetChanAttributeF64;
    SetChanAttributeF64Ptr SetChanAttributeF64;
    GetChanAttributeStrPtr GetChanAttributeStr;
    SetChanAttributeStrPtr SetChanAttributeStr;
    ReadDigitalU32Ptr ReadDigitalU32;
    ReadDigitalU32StreamPtr ReadDigitalU32Stream;
    WriteDigitalU32Ptr WriteDigitalU32;
    WriteDigitalU32StreamPtr WriteDigitalU32Stream;
    ReadAnalogF64Ptr ReadAnalogF64;
    ReadAnalogF64StreamCodegenPtr ReadAnalogF64StreamCodegen;
    ReadAnalogF64StreamCustomPtr ReadAnalogF64StreamCustom;
    WriteAnalogF64Ptr WriteAnalogF64;
    WriteAnalogF64StreamCustomPtr WriteAnalogF64StreamCustom;
    CfgSampClkTimingPtr CfgSampClkTiming;
  } FunctionLoadStatus;

  nidevice_grpc::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nidaqmx_grpc

#endif  // NIDAQMX_GRPC_LIBRARY_H
