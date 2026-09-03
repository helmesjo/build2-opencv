// HAVE_FP16

#undef HAVE_FP16

/* ARM FP16 storage-format support: conversion between the IEEE
 * half-precision and single-precision formats (e.g. vcvt_f16_f32), part
 * of the ARMv8-A NEON baseline.
 *
 * GCC, Clang: -mfpu=neon-fp16 (32-bit ARM); always available on AArch64.
 *
 * Available on Linux/glibc, MacOS. Not available under MSVC, which does
 * not define __ARM_FP.
 */
#if defined(__ARM_NEON) && defined(__ARM_FP) && (__ARM_FP & 0x2)
#  define HAVE_FP16 1
#endif
