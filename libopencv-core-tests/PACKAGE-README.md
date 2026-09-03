# libopencv-core-tests - Core functionality (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `core` module.
`test_cuda.cpp` and the top-level `test_opencl.cpp` are excluded (CUDA
and OpenCL backend test helpers; no packaged module builds either
backend), as is the entire `test/ocl/` subdirectory.
`test_logtagmanager.cpp`/`test_logtagconfigparser.cpp` are excluded too:
they `#include` core's own private implementation `.cpp` files by a
relative `../src/utils/...` path, a white-box testing style that only
works when compiled inside the main module's own source tree (as
upstream's CMake build does) and can't be replicated from a separate
sibling package without reaching into `libopencv-core`'s private `src/`
directory across a package boundary. `test_umat.cpp` is excluded: its
fixtures need the `rng`-backed helper base class that
`opencv2/ts/ocl_test.hpp` normally provides (`libopencv-ts` does not
ship it, no packaged module builds an OpenCL backend), and porting all
45 call sites was judged not worth it for this pass.

`test_io.cpp` and `test_utils.cpp` are kept, with `Core_globbing.accuracy`,
six `Core_InputOutput.filestorage_base64_basic_{read,rw}_*` cases, and
`Samples.findFile` excluded via `--gtest_filter`, since they read fixture
files from the separate `opencv_extra` test-data repository, which this
repository does not fetch.

`test_precomp.hpp`, `test_quaternion.cpp`, `test_arithm.cpp`,
`test_concatenation.cpp`, `test_operations.cpp`, and `test_io.cpp` are all
unmodified: `opencv2/ts/ocl_test.hpp` and `opencv2/ts/cuda_test.hpp` are
available from `libopencv-ts`, which matches upstream's own `ts` module
dependency list and header set, so `TestUtils`, `PARAM_TEST_CASE`, and the
`EXPECT_MAT_NEAR`/`EXPECT_MAT_N_DIFF` macros these files rely on come from
the real headers rather than a local reimplementation.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
