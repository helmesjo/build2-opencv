# libopencv-imgproc-tests - Image processing (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `imgproc` module.
`test_canny.cpp`, `test_grabcut.cpp`, `test_houghcircles.cpp`, and
`test_imgproc_umat.cpp` are excluded: their sole test cases read fixture
images from the separate `opencv_extra` test-data repository, which this
repository does not fetch. `test_watershed.cpp` is excluded too: it
contains no tests at all. The entire `test/ocl` directory does not exist
for this module.

`test_precomp.hpp` drops its unconditional `opencv2/ts/ts_gtest.h`
include (redundant: `libopencv-ts`'s `ts.hpp` already provides the real
`gtest.h`). `test_imgwarp.cpp` includes `ts_gtest.h` directly too (also
dropped), and its `DISABLED_playground` test is removed entirely (an
interactive, `#if 0`-guarded manual debugging aid never meant to run,
not something `--gtest_filter` needs to touch). `test_filter.cpp`'s two
`INSTANTIATE_TEST_CASE_P(/**/, ..., testing::Values(...), );` calls have
a trailing comma upstream tolerated against the vendored gtest fork but
real gtest 1.11 rejects (an empty macro argument); both are patched to
drop it.

A substantial minority of individual cases across otherwise-clean files
are excluded via `--gtest_filter` rather than losing their whole file,
since they read fixture files from `opencv_extra`, or (in two cases)
unconditionally `imwrite` a `.png` debug dump and this project's
`libopencv-imgcodecs` does not build PNG support: Bayer demosaicing
regressions and `Imgproc_ColorBayerVNG_Codes.regression27225_small` in
`test_color.cpp`; one case in `test_connectedcomponents.cpp`;
`Drawing.fillpoly_contours`/`.fillpoly_match_lines`/`.ttf_text`; the
`sepFilter2D` accuracy group and `GaussianBlurVsBitexact.approx` in
`test_filter.cpp`/`test_smooth_bitexact.cpp`; the standard and
probabilistic Hough line regressions in `test_houghlines.cpp`; both
`Imgproc_PhaseCorrelat(or/ion)*` real-image cases; the two
`GaussianBlur_Bitexact` regressions; `StackBlur`/`StackBlur_GaussianBlur`'s
parametrized suites; and the `Imgproc_AdaptiveThreshold` group.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
