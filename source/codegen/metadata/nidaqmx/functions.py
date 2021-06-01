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
    #int32 __CFUNC     DAQmxCreateAIVoltageChan       
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
    # int32 __CFUNC_C   DAQmxGetChanAttribute         
    #  (TaskHandle taskHandle, const char channel[], int32 attribute, void *value, ...);
    'GetChanAttributeU32': {
        'cname' : 'DAQmxGetChanAttribute',
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
    'SetChanAttributeU32': {
        'cname' : 'DAQmxSetChanAttribute',
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
    'GetChanAttributeF64': {
        'cname' : 'DAQmxGetChanAttribute',
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
            },
            {
                'direction': 'out',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
    },
    'SetChanAttributeF64': {
        'cname' : 'DAQmxSetChanAttribute',
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
            },
            {
                'direction': 'in',
                'name': 'value',
                'type': 'double',
            },
        ],
        'returns': 'int32'
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