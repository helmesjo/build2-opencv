# libopencv-stitching-tests - Images stitching (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `stitching`
module. Only `test_reprojection.cpp` is covered: upstream's accuracy-test
suite for this module is sparse (most of its testing lives in `perf/`,
out of scope here), and every other test file's sole test case reads
fixture images (`stitching/*.jpg`/`*.png`, `lena.png`, `baboon.png`) from
the separate `opencv_extra` test-data repository, which this repository
does not fetch. `test_blenders.cuda.cpp` and `test/ocl/test_warpers.cpp`
are additionally excluded as CUDA/OpenCL backend test helpers, since this
project builds neither backend.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
