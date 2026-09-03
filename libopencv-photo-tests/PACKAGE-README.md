# libopencv-photo-tests - Computational photography (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `photo` module.
`test_chromatic_aberration.cpp`, `test_cloning.cpp`, `test_decolor.cpp`,
`test_denoise_tvl1.cpp`, `test_denoising.cpp`, `test_hdr.cpp`,
`test_intelligent_scissors.cpp`, and `test_npr.cpp` are excluded: their
test cases read fixture images from the separate `opencv_extra`
test-data repository, which this repository does not fetch.
`test_denoising.cuda.cpp` is excluded too, as a CUDA backend test helper
(no packaged module builds a CUDA backend).

`test_precomp.hpp`, `test_ccm.cpp`, and `test_inpaint.cpp` are all
unmodified: `opencv2/ts/ocl_test.hpp` (for `test_ccm.cpp`'s
`EXPECT_MAT_NEAR`) and `opencv2/imgcodecs.hpp` (for both files' `imread`/
`imwrite` calls) are available from `libopencv-ts`, which matches
upstream's own `ts` module dependency list and header set.

`Photo_ColorCorrection.compute_color_correction_matrix`,
`.correct_image`, and `.serialization` (test_ccm.cpp), and
`Photo_Inpaint.regression` (test_inpaint.cpp), are excluded via
`--gtest_filter`: they too read `opencv_extra` fixture files.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
