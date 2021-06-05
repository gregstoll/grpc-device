# -*- coding: utf-8 -*-
functions = {
    'CreateSession': {
        'init_method': True,
        'parameters': [
            {
                'direction': 'in',
                'name': 'databaseName',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'clusterName',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'list',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'interface',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'mode',
                'type': 'u32',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'session',
                'type': 'nxSessionRef_t',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'nxStatus_t',
    },
    'Clear': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'nxSessionRef_t',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'nxStatus_t',
    }
}
