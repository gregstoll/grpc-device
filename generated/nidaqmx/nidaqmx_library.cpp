//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-DAQMX Metadata
//---------------------------------------------------------------------
#include "nidaqmx_library.h"

#if defined(_MSC_VER)
static const char* kLibraryName = "nicaiu.dll";
#else
static const char* kLibraryName = "libnidaqmx.so";
#endif

namespace nidaqmx_grpc {

NiDAQmxLibrary::NiDAQmxLibrary() : shared_library_(kLibraryName)
{
  shared_library_.load();
  bool loaded = shared_library_.is_loaded();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!loaded) {
    return;
  }
  function_pointers_.CreateTask = reinterpret_cast<CreateTaskPtr>(shared_library_.get_function_pointer("DAQmxCreateTask"));
  function_pointers_.ClearTask = reinterpret_cast<ClearTaskPtr>(shared_library_.get_function_pointer("DAQmxClearTask"));
  function_pointers_.StartTask = reinterpret_cast<StartTaskPtr>(shared_library_.get_function_pointer("DAQmxStartTask"));
  function_pointers_.StopTask = reinterpret_cast<StopTaskPtr>(shared_library_.get_function_pointer("DAQmxStopTask"));
  function_pointers_.ExportSignal = reinterpret_cast<ExportSignalPtr>(shared_library_.get_function_pointer("DAQmxExportSignal"));
  function_pointers_.GetExtendedErrorInfo = reinterpret_cast<GetExtendedErrorInfoPtr>(shared_library_.get_function_pointer("DAQmxGetExtendedErrorInfo"));
  function_pointers_.CreateAIVoltageChan = reinterpret_cast<CreateAIVoltageChanPtr>(shared_library_.get_function_pointer("DAQmxCreateAIVoltageChan"));
  function_pointers_.CreateAOVoltageChan = reinterpret_cast<CreateAOVoltageChanPtr>(shared_library_.get_function_pointer("DAQmxCreateAOVoltageChan"));
  function_pointers_.CreateDIChan = reinterpret_cast<CreateDIChanPtr>(shared_library_.get_function_pointer("DAQmxCreateDIChan"));
  function_pointers_.CreateDOChan = reinterpret_cast<CreateDOChanPtr>(shared_library_.get_function_pointer("DAQmxCreateDOChan"));
  function_pointers_.GetChanAttributeU32 = reinterpret_cast<GetChanAttributeU32Ptr>(shared_library_.get_function_pointer("DAQmxGetChanAttribute"));
  function_pointers_.SetChanAttributeU32 = reinterpret_cast<SetChanAttributeU32Ptr>(shared_library_.get_function_pointer("DAQmxSetChanAttribute"));
  function_pointers_.GetChanAttributeF64 = reinterpret_cast<GetChanAttributeF64Ptr>(shared_library_.get_function_pointer("DAQmxGetChanAttribute"));
  function_pointers_.SetChanAttributeF64 = reinterpret_cast<SetChanAttributeF64Ptr>(shared_library_.get_function_pointer("DAQmxSetChanAttribute"));
  function_pointers_.GetChanAttributeStr = reinterpret_cast<GetChanAttributeStrPtr>(shared_library_.get_function_pointer("DAQmxGetChanAttribute"));
  function_pointers_.SetChanAttributeStr = reinterpret_cast<SetChanAttributeStrPtr>(shared_library_.get_function_pointer("DAQmxSetChanAttribute"));
  function_pointers_.ReadDigitalU32 = reinterpret_cast<ReadDigitalU32Ptr>(shared_library_.get_function_pointer("DAQmxReadDigitalU32"));
  function_pointers_.ReadDigitalU32Stream = reinterpret_cast<ReadDigitalU32StreamPtr>(shared_library_.get_function_pointer("DAQmxReadDigitalU32"));
  function_pointers_.WriteDigitalU32 = reinterpret_cast<WriteDigitalU32Ptr>(shared_library_.get_function_pointer("DAQmxWriteDigitalU32"));
  function_pointers_.WriteDigitalU32Stream = reinterpret_cast<WriteDigitalU32StreamPtr>(shared_library_.get_function_pointer("DAQmxWriteDigitalU32"));
  function_pointers_.ReadAnalogF64 = reinterpret_cast<ReadAnalogF64Ptr>(shared_library_.get_function_pointer("DAQmxReadAnalogF64"));
  function_pointers_.ReadAnalogF64StreamCodegen = reinterpret_cast<ReadAnalogF64StreamCodegenPtr>(shared_library_.get_function_pointer("DAQmxReadAnalogF64"));
  function_pointers_.ReadAnalogF64StreamCustom = reinterpret_cast<ReadAnalogF64StreamCustomPtr>(shared_library_.get_function_pointer("DAQmxReadAnalogF64"));
  function_pointers_.WriteAnalogF64 = reinterpret_cast<WriteAnalogF64Ptr>(shared_library_.get_function_pointer("DAQmxWriteAnalogF64"));
  function_pointers_.WriteAnalogF64StreamCustom = reinterpret_cast<WriteAnalogF64StreamCustomPtr>(shared_library_.get_function_pointer("DAQmxWriteAnalogF64Stream"));
  function_pointers_.CfgSampClkTiming = reinterpret_cast<CfgSampClkTimingPtr>(shared_library_.get_function_pointer("DAQmxCfgSampClkTiming"));
}

NiDAQmxLibrary::~NiDAQmxLibrary()
{
}

::grpc::Status NiDAQmxLibrary::check_function_exists(std::string functionName)
{
  return shared_library_.function_exists(functionName.c_str())
      ? ::grpc::Status::OK
      : ::grpc::Status(::grpc::NOT_FOUND, "Could not find the function " + functionName);
}

int32 NiDAQmxLibrary::CreateTask(const char* taskName, TaskHandle* task)
{
  if (!function_pointers_.CreateTask) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxCreateTask.");
  }
#if defined(_MSC_VER)
  return DAQmxCreateTask(taskName, task);
#else
  return function_pointers_.CreateTask(taskName, task);
#endif
}

int32 NiDAQmxLibrary::ClearTask(TaskHandle task)
{
  if (!function_pointers_.ClearTask) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxClearTask.");
  }
#if defined(_MSC_VER)
  return DAQmxClearTask(task);
#else
  return function_pointers_.ClearTask(task);
#endif
  return function_pointers_.ClearTask(task);
}

int32 NiDAQmxLibrary::StartTask(TaskHandle task)
{
  if (!function_pointers_.StartTask) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxStartTask.");
  }
  return function_pointers_.StartTask(task);
}

int32 NiDAQmxLibrary::StopTask(TaskHandle task)
{
  if (!function_pointers_.StopTask) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxStopTask.");
  }
  return function_pointers_.StopTask(task);
}

int32 NiDAQmxLibrary::ExportSignal(TaskHandle task, int32 signal_id, const char* output_terminal)
{
  if (!function_pointers_.ExportSignal) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxExportSignal.");
  }
  return function_pointers_.ExportSignal(task, signal_id, output_terminal);
}

int32 NiDAQmxLibrary::GetExtendedErrorInfo(char error_string[], int32 buffer_size)
{
  if (!function_pointers_.GetExtendedErrorInfo) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxGetExtendedErrorInfo.");
  }
  return function_pointers_.GetExtendedErrorInfo(error_string, buffer_size);
}

int32 NiDAQmxLibrary::CreateAIVoltageChan(TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, int32 terminal_config, double min_val, double max_val, int32 units, const char* custom_scale_name)
{
  if (!function_pointers_.CreateAIVoltageChan) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxCreateAIVoltageChan.");
  }
  return function_pointers_.CreateAIVoltageChan(task, physical_channel, name_to_assign_to_channel, terminal_config, min_val, max_val, units, custom_scale_name);
}

int32 NiDAQmxLibrary::CreateAOVoltageChan(TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, double min_val, double max_val, int32 units, const char* custom_scale_name)
{
  if (!function_pointers_.CreateAOVoltageChan) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxCreateAOVoltageChan.");
  }
  return function_pointers_.CreateAOVoltageChan(task, physical_channel, name_to_assign_to_channel, min_val, max_val, units, custom_scale_name);
}

int32 NiDAQmxLibrary::CreateDIChan(TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping)
{
  if (!function_pointers_.CreateDIChan) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxCreateDIChan.");
  }
  return function_pointers_.CreateDIChan(task, lines, name_to_assign_to_lines, line_grouping);
}

int32 NiDAQmxLibrary::CreateDOChan(TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping)
{
  if (!function_pointers_.CreateDOChan) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxCreateDOChan.");
  }
  return function_pointers_.CreateDOChan(task, lines, name_to_assign_to_lines, line_grouping);
}

int32 NiDAQmxLibrary::GetChanAttributeU32(TaskHandle task, const char* channel, int32 attribute, uInt32* value)
{
  if (!function_pointers_.GetChanAttributeU32) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxGetChanAttribute.");
  }
  return function_pointers_.GetChanAttributeU32(task, channel, attribute, value);
}

int32 NiDAQmxLibrary::SetChanAttributeU32(TaskHandle task, const char* channel, int32 attribute, uInt32 value)
{
  if (!function_pointers_.SetChanAttributeU32) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxSetChanAttribute.");
  }
  return function_pointers_.SetChanAttributeU32(task, channel, attribute, value);
}

int32 NiDAQmxLibrary::GetChanAttributeF64(TaskHandle task, const char* channel, int32 attribute, double* value)
{
  if (!function_pointers_.GetChanAttributeF64) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxGetChanAttribute.");
  }
  return function_pointers_.GetChanAttributeF64(task, channel, attribute, value);
}

int32 NiDAQmxLibrary::SetChanAttributeF64(TaskHandle task, const char* channel, int32 attribute, double value)
{
  if (!function_pointers_.SetChanAttributeF64) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxSetChanAttribute.");
  }
  return function_pointers_.SetChanAttributeF64(task, channel, attribute, value);
}

int32 NiDAQmxLibrary::GetChanAttributeStr(TaskHandle task, const char* channel, int32 attribute, char value[], int32 size)
{
  if (!function_pointers_.GetChanAttributeStr) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxGetChanAttribute.");
  }
  return function_pointers_.GetChanAttributeStr(task, channel, attribute, value, size);
}

int32 NiDAQmxLibrary::SetChanAttributeStr(TaskHandle task, const char* channel, int32 attribute, const char* value)
{
  if (!function_pointers_.SetChanAttributeStr) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxSetChanAttribute.");
  }
  return function_pointers_.SetChanAttributeStr(task, channel, attribute, value);
}

int32 NiDAQmxLibrary::ReadDigitalU32(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved)
{
  if (!function_pointers_.ReadDigitalU32) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxReadDigitalU32.");
  }
  return function_pointers_.ReadDigitalU32(task, numSampsPerChan, timeout, fillMode, readArray, arraySizeInSamps, sampsPerChan, reserved);
}

int32 NiDAQmxLibrary::ReadDigitalU32Stream(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved)
{
  if (!function_pointers_.ReadDigitalU32Stream) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxReadDigitalU32.");
  }
  return function_pointers_.ReadDigitalU32Stream(task, numSampsPerChan, timeout, fillMode, readArray, arraySizeInSamps, sampsPerChan, reserved);
}

int32 NiDAQmxLibrary::WriteDigitalU32(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved)
{
  if (!function_pointers_.WriteDigitalU32) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxWriteDigitalU32.");
  }
  return function_pointers_.WriteDigitalU32(task, numSampsPerChan, autoStart, timeout, dataLayout, writeArray, sampsPerChanWritten, reserved);
}

int32 NiDAQmxLibrary::WriteDigitalU32Stream(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved)
{
  if (!function_pointers_.WriteDigitalU32Stream) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxWriteDigitalU32.");
  }
  return function_pointers_.WriteDigitalU32Stream(task, numSampsPerChan, autoStart, timeout, dataLayout, writeArray, sampsPerChanWritten, reserved);
}

int32 NiDAQmxLibrary::ReadAnalogF64(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved)
{
  if (!function_pointers_.ReadAnalogF64) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxReadAnalogF64.");
  }
  return function_pointers_.ReadAnalogF64(task, numSampsPerChan, timeout, fillMode, readArray, arraySizeInSamps, sampsPerChan, reserved);
}

int32 NiDAQmxLibrary::ReadAnalogF64StreamCodegen(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved)
{
  if (!function_pointers_.ReadAnalogF64StreamCodegen) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxReadAnalogF64.");
  }
  return function_pointers_.ReadAnalogF64StreamCodegen(task, numSampsPerChan, timeout, fillMode, readArray, arraySizeInSamps, sampsPerChan, reserved);
}

int32 NiDAQmxLibrary::ReadAnalogF64StreamCustom(TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved)
{
  if (!function_pointers_.ReadAnalogF64StreamCustom) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxReadAnalogF64.");
  }
  return function_pointers_.ReadAnalogF64StreamCustom(task, numSampsPerChan, timeout, fillMode, readArray, arraySizeInSamps, sampsPerChan, reserved);
}

int32 NiDAQmxLibrary::WriteAnalogF64(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved)
{
  if (!function_pointers_.WriteAnalogF64) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxWriteAnalogF64.");
  }
  return function_pointers_.WriteAnalogF64(task, numSampsPerChan, autoStart, timeout, dataLayout, writeArray, sampsPerChanWritten, reserved);
}

int32 NiDAQmxLibrary::WriteAnalogF64StreamCustom(TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved)
{
  if (!function_pointers_.WriteAnalogF64StreamCustom) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxWriteAnalogF64Stream.");
  }
  return function_pointers_.WriteAnalogF64StreamCustom(task, numSampsPerChan, autoStart, timeout, dataLayout, writeArray, sampsPerChanWritten, reserved);
}

int32 NiDAQmxLibrary::CfgSampClkTiming(TaskHandle task, const char* source, double rate, int32 active_edge, int32 sample_mode, uInt64 samps_per_chan)
{
  if (!function_pointers_.CfgSampClkTiming) {
    throw nidevice_grpc::LibraryLoadException("Could not find DAQmxCfgSampClkTiming.");
  }
  return function_pointers_.CfgSampClkTiming(task, source, rate, active_edge, sample_mode, samps_per_chan);
}

}  // namespace nidaqmx_grpc
