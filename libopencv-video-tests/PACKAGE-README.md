# libopencv-video-tests - Video analysis (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `video` module.
`test_estimaterigid.cpp` and `test_optflowpyrlk.cpp` are excluded: their
test cases read fixture images from the separate `opencv_extra`
test-data repository, which this repository does not fetch.
`test_trackers.cpp` and `test_trackers.impl.hpp` are excluded too: their
fixtures read tracking-sequence fixture data from `opencv_extra`, and the
DaSiamRPN/NanoTrack/vittrack cases additionally need ONNX models and the
unpackaged `dnn` module (their `create(Params)` calls compile without it
but throw at runtime). `test_ecc.cpp` is excluded: 5 of its 7 test groups
need `opencv_extra` fixture images (`shared/fruits.png`,
`shared/halmosh*`), outweighing its 3 fully-synthetic groups
(`Video_ECC_Test_Compute.*`).

`test_OF_accuracy.cpp` is kept, unmodified (its `imread`/`imwrite` calls
are covered by `libopencv-ts` depending on `libopencv-imgcodecs`,
matching upstream's own `ts` module dependency list), with
`DenseOpticalFlow_DIS.ReferenceAccuracy` and
`DenseOpticalFlow_VariationalRefinement.ReferenceAccuracy` excluded via
`--gtest_filter` since they too need `opencv_extra` fixture images
(`RubberWhale`); the other 3 of its 5 tests are fully synthetic.

`test_precomp.hpp` includes `opencv2/geometry.hpp` directly;
`libopencv-video` only depends on `libopencv-geometry` privately, so this
package adds it (and `libopencv-imgcodecs`) explicitly.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
