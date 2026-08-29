# libopencv-stitching - A C++ library

This is a `build2` package for the [`stitching`](https://github.com/opencv/opencv/tree/5.0.0/modules/stitching)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides image stitching: panorama composition from feature matching,
motion estimation, exposure compensation, seam finding, and blending.


## Usage

To start using `libopencv-stitching` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-stitching ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-stitching%lib{opencv-stitching}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-stitching}
```

`lib{opencv-stitching}` is the OpenCV stitching module: the high-level
`Stitcher` pipeline and its lower-level `detail` building blocks (feature
matching, motion estimation, exposure compensation, seam finding, warping,
and blending).


## Configuration variables

This package provides no configuration variables.
