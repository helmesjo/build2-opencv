# libopencv-flann - A C++ library

This is a `build2` package for the [`flann`](https://github.com/opencv/opencv/tree/5.0.0/modules/flann)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It performs clustering and fast approximate nearest-neighbor search in
multi-dimensional spaces, used throughout OpenCV for feature matching and
related tasks.


## Usage

To start using `libopencv-flann` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-flann ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-flann%lib{opencv-flann}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-flann}
```

`lib{opencv-flann}` is the OpenCV flann module: the `cv::flann::Index`
class and its supporting index/search parameter types.


## Configuration variables

This package provides no configuration variables.
