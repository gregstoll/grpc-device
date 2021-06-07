# -*- coding: utf-8 -*-
functions = {
    # NiFpga_Status NiFpga_Open(const char*     bitfile,
    #                       const char*     signature,
    #                       const char*     resource,
    #                       uint32_t        attribute,
    #                       NiFpga_Session* session);
    'Open': {
        'init_method': True,
        'custom_close_method': True,
        'custom_close': 'Close(id, 0)',
        'parameters': [
            {
                'direction': 'in',
                'name': 'bitfile',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'signature',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'resource',
                'type': 'const char*',
                'grpc_type': 'string'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'uint32_t',
                'grpc_type': 'uint32'
            },
            {
                'direction': 'out',
                'name': 'session',
                'type': 'NiFpga_Session',
                'grpc_type': 'nidevice_grpc.Session'
            }
        ],
        'returns': 'int32_t',
    },
    'Close': {
        'parameters': [
            {
                'direction': 'in',
                'name': 'session',
                'type': 'NiFpga_Session',
                'grpc_type': 'nidevice_grpc.Session'
            },
            {
                'direction': 'in',
                'name': 'attribute',
                'type': 'uint32_t',
                'grpc_type': 'uint32'
            }
        ],
        'returns': 'int32_t',
    }
}
