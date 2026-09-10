# libopencv-core - Core functionality

This is a `build2` package for the [`core`](https://github.com/opencv/opencv/tree/5.0.0/modules/core)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
provides fundamental data structures, matrix operations, and utility functions
that other modules depend on.


## Usage

To start using `libopencv-core` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-core ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-core%lib{opencv-core}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-core}
```

`lib{opencv-core}` is the OpenCV core module: `Mat`/`UMat` and the other core
data structures, matrix and array operations, XML/YAML/JSON persistence, and
common utilities (logging, threading, CPU feature detection, file system).


## Configuration variables

This package provides no configuration variables.


## CPU dispatch

OpenCV's CPU dispatch compiles compute-heavy routines once per ISA tier and
selects the best available implementation at runtime via
`checkHardwareSupport()`. Upstream CMake generates the per-ISA translation
units and their companion `*.simd_declarations.hpp` files into the build
directory at configure time; this package provides equivalent static files
under `src/simd/`. On x86_64, SSE4.1, SSE4.2, and AVX2 tiers are compiled
for the `libopencv-core` routines where upstream enables them.
