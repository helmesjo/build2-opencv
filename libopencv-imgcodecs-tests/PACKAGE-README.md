# libopencv-imgcodecs-tests - Image I/O (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `imgcodecs`
module. Only `test_bmp.cpp` and `test_sunraster.cpp` are covered: this
package only builds BMP, GIF, Sun Raster, HDR/PFM, PXM/PAM, and EXIF
metadata support (see `libopencv-imgcodecs/PACKAGE-README.md`), so every
other upstream test file either compiles to an empty no-op (gated on a
format not built) or reads fixture images from the separate `opencv_extra`
test-data repository, which this repository does not fetch — most format
test files are both. `test_bmp.cpp` also declares (via `test_common.hpp`)
but never calls a couple of shared fixture-image helpers that themselves
need `opencv_extra`; only the header is included here, not their
definitions, since nothing in the kept file actually calls them.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
