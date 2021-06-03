//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-DAQMX
//---------------------------------------------------------------------
#ifndef NIDAQMX_GRPC_MOCK_LIBRARY_H
#define NIDAQMX_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nidaqmx_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiDAQmxMockLibrary : public nidaqmx_grpc::NiDAQmxLibraryInterface {
 public:
  MOCK_METHOD(int32, CreateTask, (const char* taskName, TaskHandle* task), (override));
  MOCK_METHOD(int32, ClearTask, (TaskHandle task), (override));
  MOCK_METHOD(int32, StartTask, (TaskHandle task), (override));
  MOCK_METHOD(int32, StopTask, (TaskHandle task), (override));
  MOCK_METHOD(int32, ExportSignal, (TaskHandle task, int32 signal_id, const char* output_terminal), (override));
  MOCK_METHOD(int32, GetExtendedErrorInfo, (char error_string[], int32 buffer_size), (override));
  MOCK_METHOD(int32, ConnectTerms, (const char* source_terminal, const char* destination_terminal), (override));
  MOCK_METHOD(int32, DisconnectTerms, (const char* source_terminal, const char* destination_terminal), (override));
  MOCK_METHOD(int32, CfgDigEdgeStartTrig, (TaskHandle task, const char* trigger_source, int32 trigger_edge), (override));
  MOCK_METHOD(int32, CreateCIPulseChanFreq, (TaskHandle task, const char* counter, const char* name_to_assign_to_channel, double min_val, double max_val, int32 units), (override));
  MOCK_METHOD(int32, ReadCtrFreq, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 interleaved, float64 readArrayFrequency[], float64 readArrayDutyCycle[], uInt32 arraySizeInSamps, int32* sampsPerChanRead, uInt64 reserved), (override));
  MOCK_METHOD(int32, ReadCtrFreqStream, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 interleaved, float64 readArrayFrequency[], float64 readArrayDutyCycle[], uInt32 arraySizeInSamps, int32* sampsPerChanRead, uInt64 reserved), (override));
  MOCK_METHOD(int32, CreateAIVoltageChan, (TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, int32 terminal_config, double min_val, double max_val, int32 units, const char* custom_scale_name), (override));
  MOCK_METHOD(int32, CreateAOVoltageChan, (TaskHandle task, const char* physical_channel, const char* name_to_assign_to_channel, double min_val, double max_val, int32 units, const char* custom_scale_name), (override));
  MOCK_METHOD(int32, CreateDIChan, (TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping), (override));
  MOCK_METHOD(int32, CreateDOChan, (TaskHandle task, const char* lines, const char* name_to_assign_to_lines, int32 line_grouping), (override));
  MOCK_METHOD(int32, GetChanAttributeU32, (TaskHandle task, const char* channel, int32 attribute, uInt32* value), (override));
  MOCK_METHOD(int32, SetChanAttributeU32, (TaskHandle task, const char* channel, int32 attribute, uInt32 value), (override));
  MOCK_METHOD(int32, GetChanAttributeF64, (TaskHandle task, const char* channel, int32 attribute, double* value), (override));
  MOCK_METHOD(int32, SetChanAttributeF64, (TaskHandle task, const char* channel, int32 attribute, double value), (override));
  MOCK_METHOD(int32, GetChanAttributeStr, (TaskHandle task, const char* channel, int32 attribute, char value[], int32 size), (override));
  MOCK_METHOD(int32, SetChanAttributeStr, (TaskHandle task, const char* channel, int32 attribute, const char* value), (override));
  MOCK_METHOD(int32, ReadDigitalU32, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, ReadDigitalU32Stream, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, uInt32 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, WriteDigitalU32, (TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved), (override));
  MOCK_METHOD(int32, WriteDigitalU32Stream, (TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const uInt32* writeArray, int32* sampsPerChanWritten, uInt64 reserved), (override));
  MOCK_METHOD(int32, ReadAnalogF64, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, ReadAnalogF64StreamCodegen, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, ReadAnalogF64StreamCustom, (TaskHandle task, int32 numSampsPerChan, double timeout, int32 fillMode, float64 readArray[], uInt32 arraySizeInSamps, int32* sampsPerChan, uInt64 reserved), (override));
  MOCK_METHOD(int32, WriteAnalogF64, (TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved), (override));
  MOCK_METHOD(int32, WriteAnalogF64StreamCustom, (TaskHandle task, int32 numSampsPerChan, int32 autoStart, double timeout, int32 dataLayout, const float64* writeArray, int32* sampsPerChanWritten, uInt64 reserved), (override));
  MOCK_METHOD(int32, CfgSampClkTiming, (TaskHandle task, const char* source, double rate, int32 active_edge, int32 sample_mode, uInt64 samps_per_chan), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIDAQMX_GRPC_MOCK_LIBRARY_H
