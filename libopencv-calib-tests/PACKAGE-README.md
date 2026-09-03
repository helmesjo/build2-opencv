# libopencv-calib-tests - Camera calibration and 3D reconstruction (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `calib` module.
`test_cameracalibration.cpp`, `test_fisheye.cpp`, and
`test_multiview_calib.cpp` are excluded: their test cases read fixture
files from the separate `opencv_extra` test-data repository, which this
repository does not fetch (`test_fisheye.cpp` also `#include`s calib's
own private `../src/fisheye.hpp`, a white-box style that wouldn't have
worked from this sibling package anyway).

`test_cameracalibration_tilt.cpp` is unmodified: `opencv2/ts/cuda_test.hpp`
(for `EXPECT_MAT_NEAR`) is available from `libopencv-ts`, which matches
upstream's own `ts` module dependency list and header set.

`test_cameracalibration_artificial.cpp` includes `opencv2/objdetect.hpp`
directly, and `test_precomp.hpp` includes `opencv2/geometry.hpp`
directly; since `libopencv-calib` doesn't depend on `libopencv-objdetect`
at all otherwise, and only depends on `libopencv-geometry` privately,
this package adds both as explicit dependencies.

`Calib3d_CalibrateHandEye.regression_17986` and
`Calib3d_CalibrateRobotWorldHandEye.regression` (in the kept
`test_calibration_hand_eye.cpp`) are excluded via `--gtest_filter`: they
too read fixture files from `opencv_extra`.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
