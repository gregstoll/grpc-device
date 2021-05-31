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
                'name': 'taskHandle',
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
                'name': 'taskHandle',
                'type': 'TaskHandle',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'int32',
    },
}
