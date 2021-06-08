import grpc
import nixnet_pb2 as xnet_types
import nixnet_pb2_grpc as grpc_nixnet
import session_pb2 as session_types
import session_pb2_grpc as grpc_session
from unittest import TestCase, main

server_address = 'lvtest057'
server_port = '31763'
session_name = 'xnet'

channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nixnet.NiXnetStub(channel)
session = grpc_session.SessionUtilitiesStub(channel)
session.ResetServer(session_types.ResetServerRequest())

class XNetTest(TestCase):
    def testOpenFail(self):
        create_response = client.CreateSession(xnet_types.CreateSessionRequest(
            session_name=session_name,
            database_name='NIXNET_exampleLDF',
            cluster_name='Cluster',
            list='erSignal1_U16,MasterSignal2_U16',
            interface='LIN1',
            mode=0 # nxMode_SignalInSinglePoint
        ))

        client.Clear(xnet_types.ClearRequest(
            session=create_response.session
        ))

        self.assertEqual(-1074384758, create_response.status)

if __name__ == '__main__':
    main()