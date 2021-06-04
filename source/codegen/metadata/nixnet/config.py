# -*- coding: utf-8 -*-
config = {
    'api_version': '20.0.0',
    'c_header': 'nixnet.h',
    'c_function_prefix': 'nx',
    'service_class_prefix': 'NiXnet',
    'java_package': 'com.ni.grpc.nixnet',
    'csharp_namespace': 'NationalInstruments.Grpc.Xnet',
    'namespace_component': 'nixnet',
    'close_function': 'Clear ',
    'custom_types': [
    ],
    'driver_name': 'NI-XNET',
    'extra_errors_used': [
    ],
    'init_function': 'CreateSession',
    'resource_handle_type': 'nxSessionRef_t',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'libnixnet.so',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'nixnet.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'nixnet.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nixnet',
    'session_class_description': 'An NI-XNET session',
    'session_handle_parameter_name': 'session'
}
