# libopencv-geometry-tests - Computational geometry primitives (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `geometry` module.
All 34 upstream test files are covered; no OpenCL/CUDA test helper
directories exist for this module.

`test_moments.cpp`, `test_cameras.cpp`, `test_convhull.cpp`,
`test_fisheye.cpp`, and `test_undistort_points.cpp` are all unmodified:
`opencv2/ts/ocl_test.hpp` and `opencv2/ts/cuda_test.hpp` (for
`EXPECT_MAT_NEAR` and `cvtest::randomInt`) are available from
`libopencv-ts`, which matches upstream's own `ts` module dependency list
and header set, and `test_fisheye.cpp`'s `imread`/`imwrite` calls are
covered by `libopencv-ts` depending on `libopencv-imgcodecs` the same way.

`test_normal_estimation.cpp` includes `opencv2/flann.hpp` and
`test_fisheye.cpp` includes `opencv2/videoio.hpp` (unused) directly;
since `libopencv-geometry` only depends on `libopencv-flann` privately,
this package depends on `libopencv-flann`, `libopencv-videoio`, and
`libopencv-imgcodecs` explicitly.

`fisheyeTest.undistortImage`, `fisheyeTest.undistortAndDistortImage`, and
`Calib3d_Homography.fromImages` are excluded via `--gtest_filter`: they
read fixture images from the separate `opencv_extra` test-data
repository, which this repository does not fetch.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
