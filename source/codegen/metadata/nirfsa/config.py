# -*- coding: utf-8 -*-
config = {
    'api_version': '21.0.0',
    'c_header': 'niRFSA.h',
    'c_function_prefix': 'niRFSA_',
    'service_class_prefix': 'NiRFSA',
    'java_package': 'com.ni.grpc.nirfsa',
    'csharp_namespace': 'NationalInstruments.Grpc.NiRFSA',
    'namespace_component': 'nirfsa',
    'close_function': 'Close',
    'context_manager_name': {
        'abort_function': 'Abort',
        'initiate_function': 'Initiate',
        # TODO?
        'task': 'acquisition'
    },
    'custom_types': [
    ],
    'additional_headers': [],
    'code_readiness': 'NextRelease',
    'driver_name': 'NI-RFSA',
    # TODO?
    'extra_errors_used': [
    ],
    'init_function': 'InitWithOptions',
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'nirfsa',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niRFSA_32.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niRFSA_64.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nirfsa',
    'session_class_description': 'An NI-RFSA session to a National Instruments RF Vector Signal Analyzer.',
    'session_handle_parameter_name': 'vi'
}
