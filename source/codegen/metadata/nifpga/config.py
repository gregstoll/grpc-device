# -*- coding: utf-8 -*-
config = {
    'api_version': '20.0.0',
    'c_header': 'NiFpga.h',
    'c_function_prefix': 'NiFpgaDll_',
    'service_class_prefix': 'NiFpga',
    'java_package': 'com.ni.grpc.nifpga',
    'csharp_namespace': 'NationalInstruments.Grpc.NiFpga',
    'namespace_component': 'nifpga',
    'close_function': 'Close ',
    'custom_types': [
    ],
    'driver_name': 'NI-FPGA',
    'extra_errors_used': [
    ],
    'init_function': 'Open',
    'resource_handle_type': 'NiFpga_Session',
    'no_libs': True,
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'libNiFpga.so',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'NiFpga.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'NiFpga.dll',
                'type': 'cdll'
            }
        }
    },
    'metadata_version': '0.1',
    'module_name': 'nifpga',
    'session_class_description': 'An NI-FPGA session',
    'session_handle_parameter_name': 'session'
}
