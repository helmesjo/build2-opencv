# libopencv-features-tests - Features framework (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `features` module.
`test_affine_feature.cpp`, `test_aliked_lightglue.cpp`, `test_disk.cpp`
(plus `npy_blob.cpp`/`.hpp`, only used by the latter two),
`test_descriptors_regression.cpp`/`test_detectors_regression.cpp` (plus
their `.impl.hpp`), `test_descriptors_invariance.cpp`/
`test_detectors_invariance.cpp` (plus their `.impl.hpp` and
`test_invariance_utils.hpp`), `test_fast.cpp`, `test_goodfeaturetotrack.cpp`,
`test_keypoints.cpp`, and `test_mser.cpp` are excluded: their test cases
read fixture images from the separate `opencv_extra` test-data repository
(`test_aliked_lightglue.cpp`/`test_disk.cpp` additionally need ONNX
models and the unpackaged `dnn` module), which this repository does not
fetch. `test_precomp.hpp` is unmodified: `opencv2/ts/ocl_test.hpp` is
available from `libopencv-ts`, which matches upstream's own `ts` module
dependency list and header set.

`test_orb.cpp` and `test_sift.cpp` are kept, also unmodified (their
`imread`/`imwrite` calls are covered by `libopencv-ts` depending on
`libopencv-imgcodecs` the same way), with
`Features2D_ORB._1996`, `Features2D_ORB.MaskValue`, and
`Features2d_SIFT.descriptor_type` excluded via `--gtest_filter` since
they too need `opencv_extra` fixture images.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
