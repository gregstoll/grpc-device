import grpc
import nifpga_pb2 as fpga_t
import nifpga_pb2_grpc as grpc_nifpga
import session_pb2 as session_types
import session_pb2_grpc as grpc_session
from unittest import TestCase, main

# python -m grpc_tools.protoc -IC:\dev\grpc-device\generated\nifpga\ -IC:\dev\grpc-device\source\protobuf\ --plugin=protoc-gen-mypy=.venv\Scripts\protoc_gen_mypy.bat --python_out=. --grpc_python_out=. --mypy_out=. C:\dev\grpc-device\generated\nifpga\nifpga.proto

server_address = '10.2.66.12'
server_port = '31763'
session_name = 'fpga'

channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nifpga.NiFpgaStub(channel)
session = grpc_session.SessionUtilitiesStub(channel)
session.ResetServer(session_types.ResetServerRequest())


class FpgaTest(TestCase):
    def testOpen(self):
        create_response = client.Open(fpga_t.OpenRequest(
            session_name=session_name,
            bitfile='/home/admin/NiFpga_FpgaTest.lvbitx',
            resource='RIO0',
            signature='6451F781A4F00DFD5AF57E2FDFD149F0',
        ))

        client.Close(fpga_t.CloseRequest(
            session=create_response.session
        ))

        self.assertEqual(0, create_response.status)


if __name__ == '__main__':
    main()
