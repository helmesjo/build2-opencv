# libopencv-imgcodecs - A C++ library

This is a `build2` package for the [`imgcodecs`](https://github.com/opencv/opencv/tree/5.0.0/modules/imgcodecs)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
reads and writes image files (`cv::imread`/`cv::imwrite` and related
functions). This baseline build has every external codec library
(libjpeg, libpng, libtiff, libwebp, OpenEXR, OpenJPEG, and others) off,
leaving the built-in BMP, PXM/PAM, Sun Raster, Radiance HDR/PFM, GIF, and
EXIF-metadata support, which need no external library.


## Usage

To start using `libopencv-imgcodecs` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-imgcodecs ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-imgcodecs%lib{opencv-imgcodecs}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-imgcodecs}
```

`lib{opencv-imgcodecs}` is the OpenCV imgcodecs module: image file
reading and writing.


## Configuration variables

This package provides no configuration variables.
