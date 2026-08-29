# libopencv-stereo - A C++ library

This is a `build2` package for the [`stereo`](https://github.com/opencv/opencv/tree/5.0.0/modules/stereo)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides depth-from-stereo: stereo correspondence (disparity) matching
between rectified image pairs.


## Usage

To start using `libopencv-stereo` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-stereo ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-stereo%lib{opencv-stereo}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-stereo}
```

`lib{opencv-stereo}` is the OpenCV stereo module: stereo correspondence
(disparity) matching algorithms.


## Configuration variables

This package provides no configuration variables.
