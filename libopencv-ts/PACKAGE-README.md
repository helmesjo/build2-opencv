# libopencv-ts - Test support

This is a `build2` package for the [`ts`](https://github.com/opencv/opencv/tree/5.0.0/modules/ts)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
provides the assertion macros, `Mat`-comparison helpers, and reference-oracle
implementations that OpenCV's own module test suites are written against,
along with the OpenCL/CUDA-flavored test and performance-test helpers
(`ts/ocl_test.hpp`, `ts/cuda_test.hpp`, `ts/ocl_perf.hpp`, `ts/cuda_perf.hpp`)
that a number of modules' test files rely on for `Mat`-comparison macros
(`EXPECT_MAT_NEAR` and friends) and randomized-fixture helpers, even where
this project builds neither backend: none of that code actually needs a
real OpenCL or CUDA SDK, only OpenCV's own always-compilable `cv::ocl`/
`cv::cuda` API surface.

This package exists to support the accompanying `lib<pkg>-tests` packages
(see e.g. `libopencv-ptcloud-tests`). It is not intended for direct or
general use, and its library does not build unless a dependent explicitly
requests it, see Configuration variables below. Since the only consumers
are test packages, this package matches upstream's own module dependency
list and header set rather than trimming to the minimum its own code
strictly needs: there is no real benefit to a leaner surface here, and
matching upstream keeps every test file that relies on `ts.hpp`'s
umbrella includes (`imread`/`imwrite`/`imshow`/`waitKey` without its own
`#include`) working unmodified.

`ts.hpp` is patched (see `include/opencv2/ts.hpp.patch`) to include the
real `gtest` package instead of the vendored `ts_gtest.h`/`ts_gtest.cpp`
fork.


## Usage

To start using `libopencv-ts` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends:
\
libopencv-ts ^5.0.0
{
  require
  {
    config.libopencv_ts.build = true
  }
}
\
```

Then import the library in your `buildfile`:

```
import libs = libopencv-ts%lib{opencv-ts}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-ts}
```

`lib{opencv-ts}` is the OpenCV `ts` module: `CV_TEST_MAIN`, the `cvtest::TS`
harness, `Mat`-comparison assertions, reference-oracle implementations used
by upstream's own accuracy tests, and the OpenCL/CUDA test/perf-test helper
headers described above.


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libopencv_ts.build ?= false
```

`lib{opencv-ts}` is only part of this package's default build when this is
`true`. A `<pkg>-tests` package that depends on `libopencv-ts` sets it via a
`require` clause in its own `depends` (see Usage above) rather than relying
on the default, so `libopencv-ts` stays inert for any other consumer.
