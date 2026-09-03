// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
#include "test_precomp.hpp"

#include "test_intrin128.simd.hpp"

// see "test_intrin_emulator.cpp"
// see "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"
#define CV_CPU_OPTIMIZATION_DECLARATIONS_ONLY
#undef CV_CPU_OPTIMIZATION_NAMESPACE_BEGIN
#undef CV_CPU_OPTIMIZATION_NAMESPACE_END
#define CV_CPU_OPTIMIZATION_NAMESPACE_BEGIN namespace opt_EMULATOR_CPP {
#define CV_CPU_OPTIMIZATION_NAMESPACE_END }
#include "test_intrin128.simd.hpp"
#undef CV_CPU_OPTIMIZATION_NAMESPACE_BEGIN
#undef CV_CPU_OPTIMIZATION_NAMESPACE_END
#undef CV_CPU_OPTIMIZATION_DECLARATIONS_ONLY

#include "test_intrin128.simd_declarations.hpp"

// test_intrin256.simd.hpp/test_intrin512.simd.hpp force opencv2/core/hal/intrin.hpp
// to a 256-/512-bit width, which requires an actual AVX2/AVX512 baseline or
// dispatch variant to be configured. This project's x86 baseline stops at
// SSE2 (see libopencv-core's include/buildfile) and configures no CPU
// dispatch variants at all, so neither is ever available here (nor is a
// 256-/512-bit width meaningful on NEON, which is fixed at 128 bits): guard
// on the baseline macro (CV_CPU_DISPATCH_COMPILE_AVX2/AVX512_SKX are not
// yet known here, before opencv2/core/cv_cpu_dispatch.h is included below,
// but this project never configures dispatch variants regardless) rather
// than architecture, so this automatically starts working again if AVX2/
// AVX512 baseline support is ever added.
#if defined CV_CPU_BASELINE_COMPILE_AVX2
#undef CV_CPU_DISPATCH_MODES_ALL
#include "opencv2/core/cv_cpu_dispatch.h"
#include "test_intrin256.simd.hpp"
#include "test_intrin256.simd_declarations.hpp"
#endif

#if defined CV_CPU_BASELINE_COMPILE_AVX512_SKX
#undef CV_CPU_DISPATCH_MODES_ALL
#include "opencv2/core/cv_cpu_dispatch.h"
#include "test_intrin512.simd.hpp"
#include "test_intrin512.simd_declarations.hpp"
#endif

#ifdef _MSC_VER
# pragma warning(disable:4702)  // unreachable code
#endif

namespace opencv_test { namespace hal {

#define CV_CPU_CALL_CPP_EMULATOR_(fn, args) return (opt_EMULATOR_CPP::fn args)

#define CV_CPU_CALL_BASELINE_(fn, args)  CV_CPU_CALL_BASELINE(fn, args)

#define DISPATCH_SIMD128(fn, cpu_opt) do { \
    CV_CPU_CALL_ ## cpu_opt ## _(fn, ()); \
    throw SkipTestException("SIMD128 (" #cpu_opt ") is not available or disabled"); \
} while(0)

#define DISPATCH_SIMD256(fn, cpu_opt) do { \
    CV_CPU_CALL_ ## cpu_opt ## _(fn, ()); \
    throw SkipTestException("SIMD256 (" #cpu_opt ") is not available or disabled"); \
} while(0)

#define DISPATCH_SIMD512(fn, cpu_opt) do { \
    CV_CPU_CALL_ ## cpu_opt ## _(fn, ()); \
    throw SkipTestException("SIMD512 (" #cpu_opt ") is not available or disabled"); \
} while(0)

#define DEFINE_SIMD_TESTS(simd_size, cpu_opt) \
TEST(hal_intrin ## simd_size, uint8x16_ ## cpu_opt)  { DISPATCH_SIMD ## simd_size(test_hal_intrin_uint8, cpu_opt); } \
TEST(hal_intrin ## simd_size, int8x16_ ## cpu_opt)   { DISPATCH_SIMD ## simd_size(test_hal_intrin_int8, cpu_opt); } \
TEST(hal_intrin ## simd_size, uint16x8_ ## cpu_opt)  { DISPATCH_SIMD ## simd_size(test_hal_intrin_uint16, cpu_opt); } \
TEST(hal_intrin ## simd_size, int16x8_ ## cpu_opt)   { DISPATCH_SIMD ## simd_size(test_hal_intrin_int16, cpu_opt); } \
TEST(hal_intrin ## simd_size, int32x4_ ## cpu_opt)   { DISPATCH_SIMD ## simd_size(test_hal_intrin_int32, cpu_opt); } \
TEST(hal_intrin ## simd_size, uint32x4_ ## cpu_opt)  { DISPATCH_SIMD ## simd_size(test_hal_intrin_uint32, cpu_opt); } \
TEST(hal_intrin ## simd_size, uint64x2_ ## cpu_opt)  { DISPATCH_SIMD ## simd_size(test_hal_intrin_uint64, cpu_opt); } \
TEST(hal_intrin ## simd_size, int64x2_ ## cpu_opt)   { DISPATCH_SIMD ## simd_size(test_hal_intrin_int64, cpu_opt); } \
TEST(hal_intrin ## simd_size, float32x4_ ## cpu_opt) { DISPATCH_SIMD ## simd_size(test_hal_intrin_float32, cpu_opt); } \
TEST(hal_intrin ## simd_size, float64x2_ ## cpu_opt) { DISPATCH_SIMD ## simd_size(test_hal_intrin_float64, cpu_opt); } \

namespace intrin128 {

DEFINE_SIMD_TESTS(128, CPP_EMULATOR)

DEFINE_SIMD_TESTS(128, BASELINE)

// CV_CPU_CALL_SSE2_ (the underscore-suffixed call DISPATCH_SIMD128 uses)
// always expands to opt_SSE2::fn(...), a genuinely, separately-compiled
// dispatch namespace (see cv_cpu_helper.h) that is never declared here:
// this project configures no CPU dispatch variants (see the FP16 test
// above for the same situation). When SSE2 is only the baseline (as it
// is here), DEFINE_SIMD_TESTS(128, BASELINE) above already exercises the
// same compiled functions, so this block is both redundant and broken
// without a genuine SSE2 dispatch variant to back it.
#if defined CV_CPU_DISPATCH_COMPILE_SSE2
DEFINE_SIMD_TESTS(128, SSE2)
#endif
#if defined CV_CPU_DISPATCH_COMPILE_SSE3 || defined CV_CPU_BASELINE_COMPILE_SSE3
DEFINE_SIMD_TESTS(128, SSE3)
#endif
#if defined CV_CPU_DISPATCH_COMPILE_SSSE3 || defined CV_CPU_BASELINE_COMPILE_SSSE3
DEFINE_SIMD_TESTS(128, SSSE3)
#endif
#if defined CV_CPU_DISPATCH_COMPILE_SSE4_1 || defined CV_CPU_BASELINE_COMPILE_SSE4_1
DEFINE_SIMD_TESTS(128, SSE4_1)
#endif
#if defined CV_CPU_DISPATCH_COMPILE_SSE4_2 || defined CV_CPU_BASELINE_COMPILE_SSE4_2
DEFINE_SIMD_TESTS(128, SSE4_2)
#endif
#if defined CV_CPU_DISPATCH_COMPILE_AVX || defined CV_CPU_BASELINE_COMPILE_AVX
DEFINE_SIMD_TESTS(128, AVX)
#endif
#if defined CV_CPU_DISPATCH_COMPILE_AVX2 || defined CV_CPU_BASELINE_COMPILE_AVX2
DEFINE_SIMD_TESTS(128, AVX2)
#endif
#if defined CV_CPU_DISPATCH_COMPILE_AVX512_SKX || defined CV_CPU_BASELINE_COMPILE_AVX512_SKX
DEFINE_SIMD_TESTS(128, AVX512_SKX)
#endif

TEST(hal_intrin128, float16x8_FP16)
{
    // CV_CPU_CALL_FP16_ assumes a dispatch-style opt_FP16:: namespace with
    // its own separately-compiled translation unit, which does not exist
    // here (FP16 is a baseline feature in this build, no dispatch variants
    // are configured): call the baseline implementation directly instead
    // (cpu_baseline::, matching CV_CPU_CALL_FP16's non-underscore
    // counterpart in cv_cpu_helper.h), which is what CV_TRY_FP16 (also
    // baseline-derived here) reports as available.
#if CV_TRY_FP16
    cpu_baseline::test_hal_intrin_float16();
    return;
#endif
    throw SkipTestException("Unsupported hardware: FP16 is not available");
}

} // namespace intrin128


namespace intrin256 {

// See the guard around test_intrin256.simd.hpp's inclusion above: none of
// this namespace's content is meaningful without it.
#if defined CV_CPU_BASELINE_COMPILE_AVX2

// Not available due missing C++ backend for SIMD256
//DEFINE_SIMD_TESTS(256, BASELINE)

//#if defined CV_CPU_DISPATCH_COMPILE_AVX
//DEFINE_SIMD_TESTS(256, AVX)
//#endif

#if defined CV_CPU_DISPATCH_COMPILE_AVX2 || defined CV_CPU_BASELINE_COMPILE_AVX2
DEFINE_SIMD_TESTS(256, AVX2)
#endif

#if defined CV_CPU_DISPATCH_COMPILE_AVX512_SKX || defined CV_CPU_BASELINE_COMPILE_AVX512_SKX
DEFINE_SIMD_TESTS(256, AVX512_SKX)
#endif

TEST(hal_intrin256, float16x16_FP16)
{
#if CV_TRY_FP16
    //CV_CPU_CALL_FP16_(test_hal_intrin_float16, ());
    CV_CPU_CALL_AVX2_(test_hal_intrin_float16, ());
#endif
    throw SkipTestException("Unsupported: FP16 is not available");
}

#endif // CV_CPU_BASELINE_COMPILE_AVX2

} // namespace intrin256

namespace intrin512 {

// See the guard around test_intrin512.simd.hpp's inclusion above: none of
// this namespace's content is meaningful without it.
#if defined CV_CPU_BASELINE_COMPILE_AVX512_SKX

#if defined CV_CPU_DISPATCH_COMPILE_AVX512_SKX || defined CV_CPU_BASELINE_COMPILE_AVX512_SKX
    DEFINE_SIMD_TESTS(512, AVX512_SKX)
#endif

TEST(hal_intrin512, float16x32_FP16)
{
#if CV_TRY_FP16
    CV_CPU_CALL_AVX512_SKX_(test_hal_intrin_float16, ());
#endif
    throw SkipTestException("Unsupported: FP16 is not available");
}

#endif // CV_CPU_BASELINE_COMPILE_AVX512_SKX

} // namespace intrin512

}} // namespace