# libopencv-imgproc - A C++ library

This is a `build2` package for the [`imgproc`](https://github.com/opencv/opencv/tree/5.0.0/modules/imgproc)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides image processing: filtering, geometric transformations,
color space conversions, structural analysis (contours, shape
descriptors), histograms, and drawing/text rendering functions.


## Usage

To start using `libopencv-imgproc` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-imgproc ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-imgproc%lib{opencv-imgproc}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-imgproc}
```

`lib{opencv-imgproc}` is the OpenCV imgproc module: filtering, geometric
transformations, color conversions, structural analysis, histograms, and
drawing/text rendering.


## Configuration variables

This package provides no configuration variables.
