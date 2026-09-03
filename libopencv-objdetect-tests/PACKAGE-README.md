# libopencv-objdetect-tests - Object detection (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `objdetect`
module. `test_aruco_tutorial.cpp`, `test_chesscorners_timing.cpp`,
`test_chesscorners.cpp`, `test_mcc.cpp`, `test_qrcode_encode.cpp`, and
`test_qrcode.cpp` (plus `test_qr_utils.hpp`, only used by the latter two)
are excluded: their test cases read fixture files from the separate
`opencv_extra` test-data repository, which this repository does not
fetch. `test_barcode.cpp` is excluded too: its two parametrized,
data-driven suites dominate its actually-instantiated test count over
its three synthetic ones. `test_face.cpp` is excluded: it calls
`FaceDetectorYN::create()`/`FaceRecognizerSF::create()`, which are
unavailable without the unpackaged `dnn` module (see
`libopencv-objdetect/PACKAGE-README.md`), and its test cases are also
fully `opencv_extra`-dependent (ONNX models, labeled face data).

`test_cornerssubpix.cpp`, `test_arucodetection.cpp`, and
`test_charucodetection.cpp` are all unmodified: their `imread`/`imwrite`
calls are covered by `libopencv-ts` depending on `libopencv-imgcodecs`,
matching upstream's own `ts` module dependency list. `test_precomp.hpp`
includes `opencv2/geometry.hpp` directly; `libopencv-objdetect` only
depends on `libopencv-geometry` privately, so this package adds it (and
`libopencv-imgcodecs`) explicitly.

`CV_ArucoDetectMarkers.regression_3192`, `.regression_2492`, and
`.regression_contour_24220` (test_arucodetection.cpp), and
`Charuco.issue_14014` (test_charucodetection.cpp), are excluded via
`--gtest_filter`: they too read `opencv_extra` fixture images.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
