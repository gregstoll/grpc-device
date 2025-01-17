#ifndef NIDEVICE_GRPC_DEVICE_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_CONVERTERS_H

#include <google/protobuf/repeated_field.h>
#include <nidevice.pb.h>          // For common grpc types.
#include <server/common_types.h>  // For common C types.
#include <server/exceptions.h>

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

namespace nidevice_grpc {
namespace converters {
inline void trim_trailing_nulls(std::string& s)
{
  // Erase from the first non-null character (going backwards) to the end.
  s.erase(
      std::find_if(
          s.rbegin(),
          s.rend(),
          [](unsigned char ch) { return ch != 0; })
          .base(),
      s.end());
}

template <typename CType, typename GrpcType>
void convert_to_grpc(const CType& value, GrpcType* value_out)
{
  *value_out = static_cast<GrpcType>(value);
}

template <typename CType, typename GrpcType>
CType convert_from_grpc(const GrpcType& value)
{
  return static_cast<CType>(value);
}

template <typename CType, typename GrpcType>
inline std::vector<CType> convert_from_grpc(const google::protobuf::RepeatedPtrField<GrpcType>& input)
{
  auto output = std::vector<CType>();
  output.reserve(input.size());
  std::transform(
      input.begin(),
      input.end(),
      std::back_inserter(output),
      [&](GrpcType x) { return convert_from_grpc<CType>(x); });
  return output;
}

template <typename GrpcType, typename CType>
inline void convert_to_grpc(const std::vector<CType>& input, google::protobuf::RepeatedPtrField<GrpcType>* output)
{
  for (auto item : input) {
    auto message = new GrpcType();
    convert_to_grpc(item, message);
    output->AddAllocated(message);
  }
}

template <typename BoolType>
inline void convert_to_grpc(const std::vector<BoolType>& input, google::protobuf::RepeatedField<bool>* output)
{
  for (auto item : input) {
    output->Add(item != BoolType(0));
  }
}

template <>
inline void convert_to_grpc(const NIComplexNumberF32_struct& input, nidevice_grpc::NIComplexNumberF32* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexNumberF32_struct convert_from_grpc(const nidevice_grpc::NIComplexNumberF32& input)
{
  auto output = NIComplexNumberF32_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexSingle_struct& input, nidevice_grpc::NIComplexNumberF32* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexSingle_struct convert_from_grpc(const nidevice_grpc::NIComplexNumberF32& input)
{
  auto output = NIComplexSingle_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexNumber_struct& input, nidevice_grpc::NIComplexNumber* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexNumber_struct convert_from_grpc(const nidevice_grpc::NIComplexNumber& input)
{
  auto output = NIComplexNumber_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexDouble_struct& input, nidevice_grpc::NIComplexNumber* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexDouble_struct convert_from_grpc(const nidevice_grpc::NIComplexNumber& input)
{
  auto output = NIComplexDouble_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexI16_struct& input, nidevice_grpc::NIComplexI16* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexI16_struct convert_from_grpc(const nidevice_grpc::NIComplexI16& input)
{
  auto output = NIComplexI16_struct();
  if (input.real() < (std::numeric_limits<ViInt16>::min)() || input.real() > (std::numeric_limits<ViInt16>::max)()) {
    std::string message("value ");
    message.append(std::to_string(input.real()));
    message.append(" doesn't fit in datatype ");
    message.append("ViInt16");
    throw nidevice_grpc::ValueOutOfRangeException(message);
  }
  output.real = static_cast<ViInt16>(input.real());
  if (input.imaginary() < (std::numeric_limits<ViInt16>::min)() || input.imaginary() > (std::numeric_limits<ViInt16>::max)()) {
    std::string message("value ");
    message.append(std::to_string(input.imaginary()));
    message.append(" doesn't fit in datatype ");
    message.append("ViInt16");
    throw nidevice_grpc::ValueOutOfRangeException(message);
  }
  output.imaginary = static_cast<ViInt16>(input.imaginary());
  return output;
}

template <typename SmtSpectrumInfoType>
inline void convert_to_grpc(const SmtSpectrumInfoType& input, nidevice_grpc::SmtSpectrumInfo* output)
{
  output->set_spectrum_type(input.spectrumType);
  output->set_linear_db(input.linearDB);
  output->set_window(input.window);
  output->set_window_size(input.windowSize);
  output->set_fft_size(input.FFTSize);
}

}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_CONVERTERS_H */
