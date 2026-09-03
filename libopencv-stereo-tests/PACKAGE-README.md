# libopencv-stereo-tests - Depth from Stereo (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `stereo` module.
`test_stereomatching.cpp` is excluded: all 5 of its test entry points read
dataset fixtures from the separate `opencv_extra` test-data repository,
which this repository does not fetch. `test/opencl/test_stereobm.cpp` is
excluded too, as an OpenCL backend test helper (no packaged module
builds an OpenCL backend).

`test_geometry.cpp` is unmodified: `opencv2/ts/cuda_test.hpp` (for
`EXPECT_MAT_NEAR`) and `opencv2/imgcodecs.hpp` (for its `imread`/`imwrite`
calls) are available from `libopencv-ts`, which matches upstream's own
`ts` module dependency list and header set. Its one
`opencv_extra`-dependent case, `fisheyeTest.stereoRectify`, returns
immediately at `cvtest::debugLevel == 0` (the default), so it passes
trivially without needing an explicit `--gtest_filter` exclusion; the
rest of the file's tests are self-contained regression checks against
hardcoded matrices. `test_geometry.cpp` includes `opencv2/geometry.hpp`
directly; `libopencv-stereo` only depends on `libopencv-geometry`
privately, so this package adds it (and `libopencv-imgcodecs`)
explicitly.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
