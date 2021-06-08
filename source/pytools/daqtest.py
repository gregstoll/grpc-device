from os import write
import grpc
import nidaqmx_pb2 as daq_t
import nidaqmx_pb2_grpc as grpc_nidaq
import session_pb2 as session_types
import session_pb2_grpc as grpc_session
from unittest import TestCase, main

server_address = 'lvtest057'
server_port = '31763'
task_name = 'DaqTask'

class DaqTest(TestCase):
    def test_daq(self):
        channel = grpc.insecure_channel(f"{server_address}:{server_port}")
        client = grpc_nidaq.NiDAQmxStub(channel)
        session = grpc_session.SessionUtilitiesStub(channel)
        session.ResetServer(session_types.ResetServerRequest())

        with self.subTest('get_extended_error_info'):
            # ??? maybe a timing issue here? Doesn't pass reliably without extra stuff
            error_info_out = client.GetExtendedErrorInfo(daq_t.GetExtendedErrorInfoRequest(
                buffer_size=1024
            ))
            client.StartTask(daq_t.StartTaskRequest())
            client.StartTask(daq_t.StartTaskRequest())
            client.StartTask(daq_t.StartTaskRequest())
            error_info_out = client.GetExtendedErrorInfo(daq_t.GetExtendedErrorInfoRequest(
                buffer_size=1024
            ))

            self.assertEqual(0, error_info_out.status)
            self.assertIn('Task specified is invalid', error_info_out.error_string)

        create_response: daq_t.CreateTaskResponse = client.CreateTask(daq_t.CreateTaskRequest(
            session_name = task_name,
            task_name = task_name))

        task = create_response.task

        with self.subTest('create_analog_in'):
            chan_response = client.CreateAIVoltageChan(daq_t.CreateAIVoltageChanRequest(
                task=task,
                physical_channel='Dev1/ai0',
                name_to_assign_to_channel='ai',
                terminal_config=-1,
                min_val=-10,
                max_val=10,
                units=10348,
                custom_scale_name=''))

            self.assertEqual(0, chan_response.status)

        with self.subTest('cfg_sample_clk'):
            sample_clk_response = client.CfgSampClkTiming(daq_t.CfgSampClkTimingRequest(
                task = task,
                rate = 100,
                active_edge = 10280,
                sample_mode = 10123,
                samps_per_chan = 10
            ))

            self.assertEqual(0, sample_clk_response.status)

        with self.subTest('chan_attributes'):
            descr_response = client.SetChanAttributeString(daq_t.SetChanAttributeStringRequest(
                task=task,
                channel='ai',
                attribute=daq_t.ChannelAttributes.CHANNEL_ATTRIBUTES_ChanDescr,
                value='The first channel'
            ))
            descr_response = client.GetChanAttributeString(daq_t.GetChanAttributeStringRequest(
                task = task,
                channel='ai',
                attribute=daq_t.ChannelAttributes.CHANNEL_ATTRIBUTES_ChanDescr,
                size=256
            ))

            print(descr_response.value)
            self.assertEqual('The first channel', descr_response.value.rstrip('\x00'))

        with self.subTest("read_some_data"):
            client.StartTask(daq_t.StartTaskRequest(task=task))
            read_response = client.ReadAnalogF64(daq_t.ReadAnalogF64Request(
                task=task,
                num_samps_per_chan=10,
                timeout=100,
                fill_mode = 1,
                array_size_in_samps = 10
            ))
            first_read_data = read_response.read_array
            print(first_read_data)
            read_response = client.ReadAnalogF64(daq_t.ReadAnalogF64Request(
                task=task,
                num_samps_per_chan=10,
                timeout=100,
                fill_mode = 1,
                array_size_in_samps = 10
            ))
            self.assertNotEqual(first_read_data, read_response.read_array)

            client.StopTask(daq_t.StopTaskRequest(task=task))

        with self.subTest("read_some_data"):
            client.StartTask(daq_t.StartTaskRequest(task=task))
            read_response = client.ReadAnalogF64(daq_t.ReadAnalogF64Request(
                task=task,
                num_samps_per_chan=10,
                timeout=100,
                fill_mode = 1,
                array_size_in_samps = 10
            ))
            first_read_data = read_response.read_array
            print(first_read_data)
            read_response_stream = client.ReadAnalogF64StreamCodegen(
                daq_t.ReadAnalogF64StreamCodegenRequest(
                    task=task,
                    num_samps_per_chan=10,
                    timeout=100,
                    fill_mode = 1,
                    array_size_in_samps = 10
            ))

            first_chunk = None
            second_chunk = None
            for data in read_response_stream:
                print(data.read_array)
                if not first_chunk:
                    first_chunk = data.read_array
                elif not second_chunk:
                    second_chunk = data.read_array
                else:
                    read_response_stream.cancel()
                    break
            self.assertNotEqual(first_chunk, second_chunk)

            client.StopTask(daq_t.StopTaskRequest(task=task))

        with self.subTest('export_channel'):
            export_out = client.ExportSignal(daq_t.ExportSignalRequest(
                task = task,
                signal_id=12487,
                output_terminal='Dev2/ao0'
            ))

            self.assertEqual(0, export_out.status)

        client.ClearTask(daq_t.ClearTaskRequest(
            task = task))

        create_out = client.CreateTask(daq_t.CreateTaskRequest(
            session_name = 'cfg_timing',
            task_name = 'cfg_timing'
        ))
        task = create_out.task
        chan_response = client.CreateAIVoltageChan(daq_t.CreateAIVoltageChanRequest(
            task=task,
            physical_channel='Dev5/ai0',
            name_to_assign_to_channel='ai',
            terminal_config=-1,
            min_val=-10,
            max_val=10,
            units=10348,
            custom_scale_name=''
        ))
        with self.subTest('timing_attribute_OverrunBehavior_i32_FAIL'):
            attr_response = client.GetTimingAttributeInt32(daq_t.GetTimingAttributeInt32Request(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_OverrunBehavior,
            ))

            self.assertEqual(0, attr_response.value)
            self.assertEqual(-200452, attr_response.status)
            
        with self.subTest('timing_attribute_UnderflowBehavior_i32_FAIL'):
            attr_response = client.GetTimingAttributeInt32(daq_t.GetTimingAttributeInt32Request(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_UnderflowBehavior,
            ))

            self.assertEqual(0, attr_response.value)
            self.assertEqual(-200452, attr_response.status)

        with self.subTest('timing_attribute_double'):
            attr_response = client.GetTimingAttributeDouble(daq_t.GetTimingAttributeDoubleRequest(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_Timebase_Rate,
            ))

            self.assertEqual(100000000.0, attr_response.value)
            self.assertEqual(0, attr_response.status)

        with self.subTest('timing_attribute_string'):
            initial_response = client.GetTimingAttributeString(daq_t.GetTimingAttributeStringRequest(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_Src,
                size=1024
            ))
            
            set_response = client.SetTimingAttributeString(daq_t.SetTimingAttributeStringRequest(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_Src,
                value='/Dev5/PFI0'
            ))

            after_set_response = client.GetTimingAttributeString(daq_t.GetTimingAttributeStringRequest(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_Src,
                size=1024
            ))

            # restore to original
            restore_response = client.SetTimingAttributeString(daq_t.SetTimingAttributeStringRequest(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_Src,
                value=initial_response.value
            ))

            self.assertEqual('ai/SampleClockTimebase', initial_response.value.rstrip('\x00'))
            self.assertEqual(0, after_set_response.status)
            self.assertEqual('/Dev5/PFI0', after_set_response.value.rstrip('\x00'))
            self.assertEqual(0, restore_response.status)

            attr_response = client.GetTimingAttributeString(daq_t.GetTimingAttributeStringRequest(
                task=task,
                attribute=daq_t.TimingAttributes.TIMING_ATTRIBUTES_SampClk_Timebase_Src,
                size=1024
            ))

            self.assertEqual('100MHzTimebase', attr_response.value.rstrip('\x00'))
            self.assertEqual(0, attr_response.status)

        client.ClearTask(daq_t.ClearTaskRequest(task=task))

        create_out = client.CreateTask(daq_t.CreateTaskRequest(
            session_name = 'cfg_rt',
            task_name = 'cfg_rt'
        ))
        task = create_out.task
        chan_response = client.CreateAIVoltageChan(daq_t.CreateAIVoltageChanRequest(
            task=task,
            physical_channel='Dev5/ai0',
            name_to_assign_to_channel='ai',
            terminal_config=-1,
            min_val=-10,
            max_val=10,
            units=10348,
            custom_scale_name=''
        ))
        with self.subTest('rt_attribute_warmup_iters'):
            init_response = client.GetRealTimeAttributeUInt32(daq_t.GetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_NumOfWarmupIters
            ))

            set_response = client.SetRealTimeAttributeUInt32(daq_t.SetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_NumOfWarmupIters,
                value=105
            ))

            get_response = client.GetRealTimeAttributeUInt32(daq_t.GetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_NumOfWarmupIters
            ))

            restore_response = client.SetRealTimeAttributeUInt32(daq_t.SetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_NumOfWarmupIters,
                value=init_response.value
            ))

            self.assertEqual(
                [0,0,0,0], 
                [init_response.status, set_response.status, get_response.status, restore_response.status])
            self.assertEqual(105, get_response.value)

        with self.subTest('rt_attribute_conv_late_errors_to_warning'):
            init_response = client.GetRealTimeAttributeUInt32(daq_t.GetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_ConvLateErrorsToWarnings
            ))

            set_response = client.SetRealTimeAttributeUInt32(daq_t.SetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_ConvLateErrorsToWarnings,
                value=1
            ))

            get_response = client.GetRealTimeAttributeUInt32(daq_t.GetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_ConvLateErrorsToWarnings
            ))

            restore_response = client.SetRealTimeAttributeUInt32(daq_t.SetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_ConvLateErrorsToWarnings,
                value=0
            ))

            self.assertEqual(
                [0,0,0,0], 
                [init_response.status, set_response.status, get_response.status, restore_response.status])
            self.assertEqual(1, get_response.value)

        with self.subTest('rt_attribute_wait_mode'):
            init_response = client.GetRealTimeAttributeInt32(daq_t.GetRealTimeAttributeInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_WaitForNextSampClkWaitMode
            ))

            set_response = client.SetRealTimeAttributeInt32(daq_t.SetRealTimeAttributeInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_WaitForNextSampClkWaitMode,
                value=12524
            ))

            get_response = client.GetRealTimeAttributeInt32(daq_t.GetRealTimeAttributeUInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_WaitForNextSampClkWaitMode
            ))

            restore_response = client.SetRealTimeAttributeInt32(daq_t.SetRealTimeAttributeInt32Request(
                task=task,
                attribute=daq_t.RealTimeAttributes.REAL_TIME_ATTRIBUTES_RealTime_WaitForNextSampClkWaitMode,
                value=12523
            ))

            self.assertEqual(
                [0,0,0,0], 
                [init_response.status, set_response.status, get_response.status, restore_response.status])
            self.assertEqual(12524, get_response.value)
        
        client.ClearTask(daq_t.ClearTaskRequest(task=task))

        with self.subTest('connect_disconnect_terms_FAIL'):
            connect_result = client.ConnectTerms(daq_t.ConnectTermsRequest(
                source_terminal='',
                destination_terminal=''
            ))
            disconnect_result = client.ConnectTerms(daq_t.ConnectTermsRequest(
                source_terminal='',
                destination_terminal=''
            ))

            self.assertEqual(-89129, connect_result.status)
            self.assertEqual(-89129, disconnect_result.status)

        create_out = client.CreateTask(daq_t.CreateTaskRequest(
            session_name = 'out',
            task_name = 'out'
        ))
        task = create_out.task

        create_chan_out = client.CreateAOVoltageChan(daq_t.CreateAOVoltageChanRequest(
            task=task,
            physical_channel='Dev2/ao0',
            name_to_assign_to_channel='ao',
            min_val=-10,
            max_val=10,
            units=10348,
            custom_scale_name=''
        ))

        with self.subTest('write_some_data'):
            start_out = client.StartTask(daq_t.StartTaskRequest(
                task = task
            ))

            write_response = client.WriteAnalogF64(daq_t.WriteAnalogF64Request(
                task = task,
                num_samps_per_chan = 10,
                timeout = 100,
                data_layout = 0,
                write_array = range(0, 10)
            ))

            
            second_write_response = client.WriteAnalogF64(daq_t.WriteAnalogF64Request(
                task = task,
                num_samps_per_chan = 10,
                timeout = 100,
                data_layout = 0,
                write_array = range(0, 10)
            ))


            client.StopTask(daq_t.StopTaskRequest(
                task = task
            ))

            self.assertEqual(0, start_out.status)
            self.assertEqual(0, write_response.status)
            self.assertEqual(0, second_write_response.status)


        with self.subTest('write_streaming'):
            client.StartTask(daq_t.StartTaskRequest(
                task = task
            ))

            def request_iterator():
                yield daq_t.WriteAnalogF64StreamCustomRequest(
                    task = task,
                    num_samps_per_chan = 10,
                    timeout = 100,
                    data_layout = 0,
                    write_array = range(-10, 0))
                yield daq_t.WriteAnalogF64StreamCustomRequest(
                    task = task,
                    num_samps_per_chan = 10,
                    timeout = 100,
                    data_layout = 0,
                    write_array = range(0, -10))

            write_response = client.WriteAnalogF64StreamCustom(request_iterator())

            self.assertEqual(0, write_response.status)

            client.StopTask(daq_t.StopTaskRequest(
                task = task
            ))

        client.ClearTask(daq_t.ClearTaskRequest(task=task))

        create_out = client.CreateTask(daq_t.CreateTaskRequest(
            session_name = 'trig',
            task_name = 'trig'
        ))
        task = create_out.task

        with self.subTest('cfg_dig_edge_start_trig_FAIL'):
            config_result = client.CfgDigEdgeStartTrig(daq_t.CfgDigEdgeStartTrigRequest(
                task = task,
                trigger_source='OnboardClock',
                trigger_edge=10280
            ))

            self.assertEqual(-200477, config_result.status)

        client.ClearTask(daq_t.ClearTaskRequest(task=task))

        create_out = client.CreateTask(daq_t.CreateTaskRequest(
            session_name = 'counter',
            task_name = 'counter'
        ))
        task = create_out.task

        with self.subTest('create_ci_pulse_freq'):
            config_result = client.CreateCIPulseChanFreq(daq_t.CreateCIPulseChanFreqRequest(
                task = task,
                counter='Dev5/ctr1',
                name_to_assign_to_channel='ctr',
                min_val=1000,
                max_val=10000,
                units=10373
            ))

            self.assertEqual(0, config_result.status)

        with self.subTest('read_ctr_freq'):
            client.StartTask(daq_t.StartTaskRequest(task=task))
            read_result = client.ReadCtrFreq(daq_t.ReadCtrFreqRequest(
                task = task,
                num_samps_per_chan=10,
                timeout=100,
                array_size_in_samps=10
            ))
            client.StopTask(daq_t.StopTaskRequest(task=task))

            self.assertEqual(0, read_result.status)
            self.assertEqual(10, read_result.samps_per_chan_read)

        with self.subTest('read_ctr_freq_stream'):
            client.StartTask(daq_t.StartTaskRequest(task=task))

            read_iter = client.ReadCtrFreqStream(daq_t.ReadCtrFreqStreamRequest(
                task = task,
                num_samps_per_chan=10,
                timeout=100,
                array_size_in_samps=10
            ))

            for _, read_result in zip(range(0, 2), read_iter):
                self.assertEqual(0, read_result.status)
                self.assertEqual(10, read_result.samps_per_chan_read)

            client.StopTask(daq_t.StopTaskRequest(task=task))
            
        client.ClearTask(daq_t.ClearTaskRequest(task=task))

        create_out = client.CreateTask(daq_t.CreateTaskRequest(
                    session_name = 'di',
                    task_name = 'di'
                ))
        task = create_out.task

        create_response = client.CreateDIChan(daq_t.CreateDIChanRequest(
                task = task,
                lines='Dev3/port0/line0',
                name_to_assign_to_lines='di',
                line_grouping=0
            ))

        with self.subTest('read_di_chan'):
            client.StartTask(daq_t.StartTaskRequest(task=task))
            read_response = client.ReadDigitalU32(daq_t.ReadDigitalU32Request(
                task = task,
                num_samps_per_chan = 10,
                timeout = 100,
                fill_mode=1,
                array_size_in_samps=10
            ))

            client.StopTask(daq_t.StopTaskRequest(task=task))
            print(read_response.read_array)
            self.assertEqual(0, create_response.status)
            self.assertEqual(0, read_response.status)
            self.assertGreater(sum(read_response.read_array), 0)
            self.assertLessEqual(sum(read_response.read_array), 10)

        with self.subTest('read_di_chan_u16'):
            client.StartTask(daq_t.StartTaskRequest(task=task))
            read_response = client.ReadDigitalU16(daq_t.ReadDigitalU16Request(
                task = task,
                num_samps_per_chan = 10,
                timeout = 100,
                fill_mode=1,
                array_size_in_samps=10
            ))

            client.StopTask(daq_t.StopTaskRequest(task=task))
            print(read_response.read_array)
            self.assertEqual(0, create_response.status)
            self.assertEqual(0, read_response.status)
            self.assertGreater(sum(read_response.read_array), 0)
            self.assertLessEqual(sum(read_response.read_array), 10)

        with self.subTest('stream_di_chan'):
            client.StartTask(daq_t.StartTaskRequest(task=task))

            for count, read_response in enumerate(client.ReadDigitalU32Stream(daq_t.ReadDigitalU32StreamRequest(
                task = task,
                num_samps_per_chan = 10,
                timeout = 100,
                fill_mode=1,
                array_size_in_samps=10
            ))):
                self.assertEqual(0, create_response.status)
                self.assertEqual(0, read_response.status)
                self.assertGreater(sum(read_response.read_array), 0)
                self.assertLessEqual(sum(read_response.read_array), 10)
                if count > 2:
                    break
            
            client.StopTask(daq_t.StopTaskRequest(task=task))

            self.assertEqual(count, 3)

        with self.subTest('stream_di_chan_u16'):
            client.StartTask(daq_t.StartTaskRequest(task=task))

            for count, read_response in enumerate(client.ReadDigitalU16Stream(daq_t.ReadDigitalU16StreamRequest(
                task = task,
                num_samps_per_chan = 10,
                timeout = 100,
                fill_mode=1,
                array_size_in_samps=10
            ))):
                self.assertEqual(0, create_response.status)
                self.assertEqual(0, read_response.status)
                self.assertGreater(sum(read_response.read_array), 0)
                self.assertLessEqual(sum(read_response.read_array), 10)
                if count > 2:
                    break
            
            client.StopTask(daq_t.StopTaskRequest(task=task))

            self.assertEqual(count, 3)
            
        client.ClearTask(daq_t.ClearTaskRequest(
            task = task
        ))
        
        with self.subTest('create_do_chan'):
            create_out = client.CreateTask(daq_t.CreateTaskRequest(
                session_name = 'do',
                task_name = 'do'
            ))
            task = create_out.task

            create_response = client.CreateDOChan(daq_t.CreateDOChanRequest(
                task = task,
                lines='Dev4/port0/line0',
                name_to_assign_to_lines='d0',
                line_grouping=0
            ))
            self.assertEqual(0, create_response.status)

        with self.subTest('write_do_chan'):
            client.StartTask(daq_t.StartTaskRequest(task=task))

            write_response = client.WriteDigitalU32(daq_t.WriteDigitalU32Request(
                task = task,
                auto_start=1,
                num_samps_per_chan=10,
                timeout=1000,
                write_array=[0, 1] * 5
            ))

            self.assertEqual(0, write_response.status)
            client.StopTask(daq_t.StopTaskRequest(task=task))

        with self.subTest('write_do_chan_u16'):
            client.StartTask(daq_t.StartTaskRequest(task=task))

            write_response = client.WriteDigitalU16(daq_t.WriteDigitalU16Request(
                task = task,
                auto_start=1,
                num_samps_per_chan=10,
                timeout=1000,
                write_array=b'\x00\x00\x01\x00' * 5
            ))

            self.assertEqual(0, write_response.status)
            client.StopTask(daq_t.StopTaskRequest(task=task))

        with self.subTest('write_do_chan_stream'):
            client.StartTask(daq_t.StartTaskRequest(task=task))

            def request_iterator():
                yield daq_t.WriteDigitalU32Request(
                    task = task,
                    auto_start=1,
                    num_samps_per_chan=10,
                    timeout=1000,
                    write_array=[0, 1] * 5
                )
                yield daq_t.WriteDigitalU32Request(
                    task = task,
                    auto_start=1,
                    num_samps_per_chan=10,
                    timeout=1000,
                    write_array=[0, 1, 1, 1, 0] * 2
                )

            write_response = client.WriteDigitalU32Stream(request_iterator())
            client.StopTask(daq_t.StopTaskRequest(task=task))

            self.assertEqual(0, write_response.status)

        with self.subTest('write_do_chan_stream_u16'):
            client.StartTask(daq_t.StartTaskRequest(task=task))

            def request_iterator():
                yield daq_t.WriteDigitalU16Request(
                    task = task,
                    auto_start=1,
                    num_samps_per_chan=10,
                    timeout=1000,
                    write_array=b'\x00\x00\x01\x00' * 5
                )
                yield daq_t.WriteDigitalU16Request(
                    task = task,
                    auto_start=1,
                    num_samps_per_chan=10,
                    timeout=1000,
                    write_array=b'\x01\x00\x01\x00' * 5
                )

            write_response = client.WriteDigitalU16Stream(request_iterator())
            client.StopTask(daq_t.StopTaskRequest(task=task))

            self.assertEqual(0, write_response.status)

        client.ClearTask(daq_t.ClearTaskRequest(
            task = task
        ))

if __name__ == '__main__':
    main()
