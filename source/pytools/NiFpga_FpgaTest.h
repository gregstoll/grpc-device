/*
 * Generated with the FPGA Interface C API Generator 20.0
 * for NI-RIO 20.0 or later.
 */
#ifndef __NiFpga_FpgaTest_h__
#define __NiFpga_FpgaTest_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 200
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_FpgaTest_Bitfile;
 */
#define NiFpga_FpgaTest_Bitfile "NiFpga_FpgaTest.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_FpgaTest_Signature = "6451F781A4F00DFD5AF57E2FDFD149F0";

#if NiFpga_Cpp
extern "C"
{
#endif

typedef enum
{
   NiFpga_FpgaTest_IndicatorBool_BoolOut = 0x18026
} NiFpga_FpgaTest_IndicatorBool;

typedef enum
{
   NiFpga_FpgaTest_IndicatorI8_I8Out = 0x1800A
} NiFpga_FpgaTest_IndicatorI8;

typedef enum
{
   NiFpga_FpgaTest_IndicatorU8_U8Out = 0x18006
} NiFpga_FpgaTest_IndicatorU8;

typedef enum
{
   NiFpga_FpgaTest_IndicatorI16_I16 = 0x18002
} NiFpga_FpgaTest_IndicatorI16;

typedef enum
{
   NiFpga_FpgaTest_IndicatorU16_U16Out = 0x18016
} NiFpga_FpgaTest_IndicatorU16;

typedef enum
{
   NiFpga_FpgaTest_IndicatorI32_I32Out = 0x1800C
} NiFpga_FpgaTest_IndicatorI32;

typedef enum
{
   NiFpga_FpgaTest_IndicatorU32_U32Out = 0x18018
} NiFpga_FpgaTest_IndicatorU32;

typedef enum
{
   NiFpga_FpgaTest_IndicatorI64_I64Out = 0x18010
} NiFpga_FpgaTest_IndicatorI64;

typedef enum
{
   NiFpga_FpgaTest_IndicatorU64_U64Out = 0x1801C
} NiFpga_FpgaTest_IndicatorU64;

typedef enum
{
   NiFpga_FpgaTest_ControlBool_BoolIn = 0x18022
} NiFpga_FpgaTest_ControlBool;

typedef enum
{
   NiFpga_FpgaTest_ControlI8_I8In = 0x1802A
} NiFpga_FpgaTest_ControlI8;

typedef enum
{
   NiFpga_FpgaTest_ControlU8_U8In = 0x1803A
} NiFpga_FpgaTest_ControlU8;

typedef enum
{
   NiFpga_FpgaTest_ControlI16_I16In = 0x1802E
} NiFpga_FpgaTest_ControlI16;

typedef enum
{
   NiFpga_FpgaTest_ControlU16_U16In = 0x1803E
} NiFpga_FpgaTest_ControlU16;

typedef enum
{
   NiFpga_FpgaTest_ControlI32_I32In = 0x18030
} NiFpga_FpgaTest_ControlI32;

typedef enum
{
   NiFpga_FpgaTest_ControlU32_U32In = 0x18040
} NiFpga_FpgaTest_ControlU32;

typedef enum
{
   NiFpga_FpgaTest_ControlI64_I64In = 0x18034
} NiFpga_FpgaTest_ControlI64;

typedef enum
{
   NiFpga_FpgaTest_ControlU64_U64In = 0x18044
} NiFpga_FpgaTest_ControlU64;

typedef enum
{
   NiFpga_FpgaTest_IndicatorArrayI16_I16ArrayOut = 0x1804C
} NiFpga_FpgaTest_IndicatorArrayI16;

typedef enum
{
   NiFpga_FpgaTest_IndicatorArrayI16Size_I16ArrayOut = 8
} NiFpga_FpgaTest_IndicatorArrayI16Size;

typedef enum
{
   NiFpga_FpgaTest_IndicatorArrayU64_U64ArrayOut = 0x18050
} NiFpga_FpgaTest_IndicatorArrayU64;

typedef enum
{
   NiFpga_FpgaTest_IndicatorArrayU64Size_U64ArrayOut = 8
} NiFpga_FpgaTest_IndicatorArrayU64Size;

typedef enum
{
   NiFpga_FpgaTest_ControlArrayI16_I16ArrayIn = 0x18048
} NiFpga_FpgaTest_ControlArrayI16;

typedef enum
{
   NiFpga_FpgaTest_ControlArrayI16Size_I16ArrayIn = 8
} NiFpga_FpgaTest_ControlArrayI16Size;

typedef enum
{
   NiFpga_FpgaTest_ControlArrayU64_U64ArrayIn = 0x18054
} NiFpga_FpgaTest_ControlArrayU64;

typedef enum
{
   NiFpga_FpgaTest_ControlArrayU64Size_U64ArrayIn = 8
} NiFpga_FpgaTest_ControlArrayU64Size;


#if NiFpga_Cpp
}
#endif

#endif
