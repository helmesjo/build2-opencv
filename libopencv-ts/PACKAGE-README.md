# libopencv-ts - Test support

This is a `build2` package for the [`ts`](https://github.com/opencv/opencv/tree/5.0.0/modules/ts)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
provides the assertion macros, `Mat`-comparison helpers, and reference-oracle
implementations that OpenCV's own module test suites are written against.
This package exists to support the accompanying `lib<pkg>-tests` packages and
is not intended for direct or general use. Upstream builds this module as a
static library (`OPENCV_MODULE_TYPE STATIC`) and links gtest statically as
well. `ts.hpp` is patched to include the real `gtest` package instead of the
vendored `ts_gtest.h`/`ts_gtest.cpp` fork.


## Usage

To start using `libopencv-ts` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-ts ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-ts%liba{opencv-ts}
```


## Importable targets

This package provides the following importable targets:

```
liba{opencv-ts}
```

`liba{opencv-ts}` is the OpenCV `ts` module: `CV_TEST_MAIN`, the `cvtest::TS`
harness, `Mat`-comparison assertions, and reference-oracle implementations
used by upstream's own accuracy tests. Only the static variant is provided.


## Configuration variables

This package provides no configuration variables.
