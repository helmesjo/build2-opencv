# libopencv-ts - Test support

This is a `build2` package for the [`ts`](https://github.com/opencv/opencv/tree/5.0.0/modules/ts)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
provides the assertion macros, `Mat`-comparison helpers, and reference-oracle
implementations that OpenCV's own module test suites are written against.

This package exists to support the accompanying `lib<pkg>-tests` packages
(see e.g. `libopencv-ptcloud-tests`). It is not intended for direct or
general use, and its library does not build unless a dependent explicitly
requests it, see Configuration variables below.

Upstream's `ts.hpp` unconditionally vendors its own bundled Google Test fork
(`ts_gtest.h`/`ts_gtest.cpp`) and unconditionally includes `imgcodecs.hpp`,
`videoio.hpp`, and `highgui.hpp`, none of which this package's own code (or
this repository's OpenCL/CUDA-less builds) actually uses outside upstream's
optional `ocl_test.hpp`/`cuda_test.hpp` backend-test helpers, which this
package does not include. `ts.hpp` is patched (see
`include/opencv2/ts.hpp.patch`) to include the real `gtest` package instead
of the vendored fork, and to drop those three unconditional includes. A
`<pkg>-tests` package whose upstream test files rely on the transitive
`imgcodecs.hpp`/`videoio.hpp`/`highgui.hpp` include must add its own direct
dependency and `#include` instead.


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
harness, `Mat`-comparison assertions, and reference-oracle implementations
used by upstream's own accuracy tests. The performance-testing half
(`ts/ts_perf.hpp`) is included; upstream's OpenCL/CUDA backend test helpers
(`ts/ocl_test.hpp`, `ts/cuda_test.hpp`) are not, since no module packaged in
this repository builds either backend.


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libopencv_ts.build ?= false
```

`lib{opencv-ts}` is only part of this package's default build when this is
`true`. A `<pkg>-tests` package that depends on `libopencv-ts` sets it via a
`require` clause in its own `depends` (see Usage above) rather than relying
on the default, so `libopencv-ts` stays inert for any other consumer.
