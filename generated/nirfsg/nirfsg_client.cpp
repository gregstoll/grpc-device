
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-RFSG.
//---------------------------------------------------------------------
#include "nirfsg_client.h"

#include <grpcpp/grpcpp.h>

#include <nirfsg.grpc.pb.h>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

namespace nirfsg_grpc::experimental::client {

InitResponse
init(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset)
{
  ::grpc::ClientContext context;

  auto request = InitRequest{};
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset(reset);

  auto response = InitResponse{};

  raise_if_error(
      stub->Init(&context, request, &response));

  return response;
}

CloseResponse
close(const StubPtr& stub, const nidevice_grpc::Session& vi)
{
  ::grpc::ClientContext context;

  auto request = CloseRequest{};
  request.mutable_vi()->CopyFrom(vi);

  auto response = CloseResponse{};

  raise_if_error(
      stub->Close(&context, request, &response));

  return response;
}

InitWithOptionsResponse
init_with_options(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset_device, const pb::string& option_string)
{
  ::grpc::ClientContext context;

  auto request = InitWithOptionsRequest{};
  request.set_resource_name(resource_name);
  request.set_id_query(id_query);
  request.set_reset_device(reset_device);
  request.set_option_string(option_string);

  auto response = InitWithOptionsResponse{};

  raise_if_error(
      stub->InitWithOptions(&context, request, &response));

  return response;
}

ErrorMessageResponse
error_message(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& error_code)
{
  ::grpc::ClientContext context;

  auto request = ErrorMessageRequest{};
  request.mutable_vi()->CopyFrom(vi);
  request.set_error_code(error_code);

  auto response = ErrorMessageResponse{};

  raise_if_error(
      stub->ErrorMessage(&context, request, &response));

  return response;
}


} // namespace nirfsg_grpc::experimental::client
