# libopencv-geometry - A C++ library

This is a `build2` package for the [`geometry`](https://github.com/opencv/opencv/tree/5.0.0/modules/geometry)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides computational geometry primitives: 2D contour and shape
analysis, camera calibration and pose estimation (PnP, homography,
fundamental/essential matrix estimation), and related point-cloud
utilities.


## Usage

To start using `libopencv-geometry` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-geometry ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-geometry%lib{opencv-geometry}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-geometry}
```

`lib{opencv-geometry}` is the OpenCV geometry module: 2D/3D geometric
primitives, contour analysis, camera calibration, and pose estimation.


## Configuration variables

This package provides no configuration variables.
