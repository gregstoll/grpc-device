# -*- coding: utf-8 -*-
functions = {
    'CreateTask': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'taskName',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'out',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'int32',
    },
    'ClearTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'int32',
    },
    'StartTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'int32',
    },
    'StopTask': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'int32',
    },
    # int32 __CFUNC     DAQmxExportSignal
    # (TaskHandle taskHandle, int32 signalID, const char outputTerminal[]);
    'ExportSignal': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'signal_id',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'output_terminal',
                'type': 'const char*',
                'grpc_type': 'string'
            }
        ],
        'returns': 'int32',
    },
    # int32 __CFUNC     DAQmxGetExtendedErrorInfo
    # (char errorString[], uInt32 bufferSize);
    'GetExtendedErrorInfo': {
        'parameters': [
            {
                'direction': 'out',
                'name': 'error_string',
                'type': 'char[]',
                'grpc_type': 'string',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'buffer_size'
                }
            },
            {
                'direction': 'in',
                'name': 'buffer_size',
                'type': 'int32',
            },
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxConnectTerms
    # (const char sourceTerminal[], const char destinationTerminal[],
    # int32 signalModifiers);
    'ConnectTerms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'source_terminal',
                'type': 'const char*',
                'grpc_type': 'string',
            },
            {
                'direction': 'in',
                'name': 'destination_terminal',
                'type': 'const char*',
                'grpc_type': 'string',
            },
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxDisconnectTerms
    # (const char sourceTerminal[], const char destinationTerminal[]);
    'DisconnectTerms': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'source_terminal',
                'type': 'const char*',
                'grpc_type': 'string',
            },
            {
                'direction': 'in',
                'name': 'destination_terminal',
                'type': 'const char*',
                'grpc_type': 'string',
            },
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxCfgDigEdgeStartTrig
    # (TaskHandle taskHandle, const char triggerSource[], int32 triggerEdge);
    'CfgDigEdgeStartTrig': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'trigger_source',
                'type': 'const char*',
                'grpc_type': 'string',
            },
            {
                'direction': 'in',
                'name': 'trigger_edge',
                'type': 'int32',
            },
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxCreateCIPulseChanFreq
    # (TaskHandle taskHandle, const char counter[], const char nameToAssignToChannel[],
    # float64 minVal, float64 maxVal, int32 units);
    'CreateCIPulseChanFreq': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'counter',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'name_to_assign_to_channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'min_val',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'max_val',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'units',
                'type': 'int32',
            }
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxReadCtrFreq
    # (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout,
    # bool32 interleaved, float64 readArrayFrequency[], float64 readArrayDutyCycle[],
    # uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved);
    'ReadCtrFreq': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'interleaved',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArrayFrequency',
                'type': 'float64[]',
                'grpc_type': 'repeated double',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'out',
                'name': 'readArrayDutyCycle',
                'type': 'float64[]',
                'grpc_type': 'repeated double',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',
            }
        ],
        'returns': 'int32',
    },
    'ReadCtrFreqStream': {
        'cname': 'DAQmxReadCtrFreq',
        'stream_out': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'interleaved',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArrayFrequency',
                'type': 'float64[]',
                'grpc_type': 'repeated double',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'out',
                'name': 'readArrayDutyCycle',
                'type': 'float64[]',
                'grpc_type': 'repeated double',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanRead',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',
            }
        ],
        'returns': 'int32',
    },
    # int32 __CFUNC     DAQmxCreateAIVoltageChan
    # (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[],
    # int32 terminalConfig, float64 minVal, float64 maxVal, int32 units,
    # const char customScaleName[]);
    'CreateAIVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'physical_channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'name_to_assign_to_channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'terminal_config',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'min_val',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'max_val',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'units',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'custom_scale_name',
                'type': 'const char*',
                'grpc_type': 'string'
            }
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxCreateAOVoltageChan
    # (TaskHandle taskHandle, const char physicalChannel[], const char nameToAssignToChannel[], float64 minVal, float64 maxVal,
    # int32 units, const char customScaleName[]);
    'CreateAOVoltageChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'physical_channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'name_to_assign_to_channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'min_val',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'max_val',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'units',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'custom_scale_name',
                'type': 'const char*',
                'grpc_type': 'string'
            }
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxCreateDIChan
    # (TaskHandle taskHandle, const char lines[], const char nameToAssignToLines[], int32 lineGrouping);
    'CreateDIChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'name_to_assign_to_lines',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'line_grouping',
                'type': 'int32',
            }
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxCreateDOChan              (TaskHandle taskHandle, const char lines[], const char nameToAssignToLines[], int32 lineGrouping);
    'CreateDOChan': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'lines',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'name_to_assign_to_lines',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'line_grouping',
                'type': 'int32',
            }
        ],
        'returns': 'int32'
    },
    'GetChanAttributeUInt32': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
        ],
        'returns': 'int32'
    },
    'SetChanAttributeUInt32': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
        ],
        'returns': 'int32'
    },
    'GetChanAttributeInt32': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'SetChanAttributeInt32': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetChanAttributeDouble': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
    },
    'SetChanAttributeDouble': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
    },
    'GetChanAttributeString': {
        'cname': 'DAQmxGetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'char[]',
                'grpc_type': 'string',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                }
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32',
            },
        ],
        'returns': 'int32'
    },
    'SetChanAttributeString': {
        'cname': 'DAQmxSetChanAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'channel',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'ChannelAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char*',
                'grpc_type': 'string'
            },
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeUInt32': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeUInt32': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeInt32': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeInt32': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeDouble': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeDouble': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
    },
    'GetTimingAttributeString': {
        'cname': 'DAQmxGetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'char[]',
                'grpc_type': 'string',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                }
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32',
            },
        ],
        'returns': 'int32'
    },
    'SetTimingAttributeString': {
        'cname': 'DAQmxSetTimingAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'TimingAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char*',
                'grpc_type': 'string'
            },
        ],
        'returns': 'int32'
    },
    'GetRealTimeAttributeUInt32': {
        'cname': 'DAQmxGetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
        ],
        'returns': 'int32'
    },
    'SetRealTimeAttributeUInt32': {
        'cname': 'DAQmxSetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
        ],
        'returns': 'int32'
    },
    'GetRealTimeAttributeInt32': {
        'cname': 'DAQmxGetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'SetRealTimeAttributeInt32': {
        'cname': 'DAQmxSetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetRealTimeAttributeDouble': {
        'cname': 'DAQmxGetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
    },
    'SetRealTimeAttributeDouble': {
        'cname': 'DAQmxSetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
    },
    'GetRealTimeAttributeString': {
        'cname': 'DAQmxGetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'char[]',
                'grpc_type': 'string',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'size'
                }
            },
            {
                'direction': 'in',
                'name': 'size',
                'type': 'int32',
            },
        ],
        'returns': 'int32'
    },
    'SetRealTimeAttributeString': {
        'cname': 'DAQmxSetRealTimeAttribute',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'int32',
                'enum': 'RealTimeAttributes'
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'const char*',
                'grpc_type': 'string'
            },
        ],
        'returns': 'int32'
    },
    # int32 __CFUNC     DAQmxReadDigitalU32
    # (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, uInt32 readArray[],
    # uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved);
    'ReadDigitalU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'fillMode',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'type': 'uInt32[]',
                'grpc_type': 'repeated uint32',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',
            }
        ],
        'returns': 'int32',
    },
    'ReadDigitalU32Stream': {
        'stream_out': True,
        'cname': 'DAQmxReadDigitalU32',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'fillMode',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'type': 'uInt32[]',
                'grpc_type': 'repeated uint32',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',
            }
        ],
        'returns': 'int32',
    },
    'ReadDigitalU16': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'fillMode',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'type': 'uInt16[]',
                'grpc_type': 'bytes',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',
            }
        ],
        'returns': 'int32',
    },
    'ReadDigitalU16Stream': {
        'codegen_method': 'CustomCode',
        'stream_out': True,
        'cname': 'DAQmxReadDigitalU16',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'fillMode',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'type': 'uInt16[]',
                'grpc_type': 'bytes',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',
            }
        ],
        'returns': 'int32',
    },
    # int32 __CFUNC     DAQmxWriteDigitalU32
    # (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout,
    # bool32 dataLayout, const uInt32 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved);
    'WriteDigitalU32': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'dataLayout',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt32*',
                'grpc_type': 'repeated uint32',
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    'WriteDigitalU32Stream': {
        'stream_in': True,
        'cname': 'DAQmxWriteDigitalU32',
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'dataLayout',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt32*',
                'grpc_type': 'repeated uint32',
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    'WriteDigitalU16': {
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'dataLayout',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt16*',
                'grpc_type': 'bytes',
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    'WriteDigitalU16Stream': {
        'stream_in': True,
        'cname': 'DAQmxWriteDigitalU16',
        'codegen_method': 'CustomCode',
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'dataLayout',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const uInt16*',
                'grpc_type': 'bytes',
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    # int32 __CFUNC     DAQmxReadAnalogF64
    # (TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode,
    # float64 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved);
    'ReadAnalogF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'fillMode',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'type': 'float64[]',
                'grpc_type': 'repeated double',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',
            }
        ],
        'returns': 'int32',
    },
    'ReadAnalogF64StreamCodegen': {
        'cname': 'DAQmxReadAnalogF64',
        'stream_out': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'fillMode',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'type': 'float64[]',
                'grpc_type': 'repeated double',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    'ReadAnalogF64StreamCustom': {
        'cname': 'DAQmxReadAnalogF64',
        'codegen_method': 'CustomCode',
        'stream_out': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'fillMode',
                'type': 'int32',
            },
            {
                'direction': 'out',
                'name': 'readArray',
                'type': 'float64[]',
                'grpc_type': 'repeated double',
                'size': {
                    'mechanism': 'passed-in',
                    'value': 'arraySizeInSamps'
                }
            },
            {
                'direction': 'in',
                'name': 'arraySizeInSamps',
                'type': 'uInt32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'sampsPerChan',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    # int32 __CFUNC     DAQmxWriteAnalogF64
    # (TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout,
    # const float64 writeArray[], int32 *sampsPerChanWritten, bool32 *reserved);
    'WriteAnalogF64': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'dataLayout',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const float64*',
                'grpc_type': 'repeated double',
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    'WriteAnalogF64StreamCustom': {
        'cname': 'DAQmxWriteAnalogF64Stream',
        'codegen_method': 'CustomCode',
        'stream_in': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'numSampsPerChan',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'autoStart',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'timeout',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'dataLayout',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'writeArray',
                'type': 'const float64*',
                'grpc_type': 'repeated double',
            },
            {
                'direction': 'out',
                'name': 'sampsPerChanWritten',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'reserved',
                'type': 'uInt64',
                'grpc_type': 'uint64',

            }
        ],
        'returns': 'int32',
    },
    'CfgSampClkTiming': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'task',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'source',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'rate',
                'type': 'double',
            },
            {
                'direction': 'in',
                'name': 'active_edge',
                'type': 'int32',
            },
            {
                'direction': 'in',
                'name': 'sample_mode',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'samps_per_chan',
                'type': 'uInt64',
                'grpc_type': 'uint64'
            }
        ],
        'returns': 'int32',
    }
}
