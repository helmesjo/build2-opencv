# libopencv-calib - A C++ library

This is a `build2` package for the [`calib`](https://github.com/opencv/opencv/tree/5.0.0/modules/calib)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides camera calibration and 3D reconstruction: single and stereo
camera calibration, hand-eye calibration, and the fisheye camera model.


## Usage

To start using `libopencv-calib` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-calib ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-calib%lib{opencv-calib}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-calib}
```

`lib{opencv-calib}` is the OpenCV calib module: camera calibration, 3D
reconstruction, hand-eye calibration, and the fisheye camera model. The
backward-compatible `opencv2/calib3d.hpp` header (which additionally pulls
in the `stereo` module) is not part of this package.


## Configuration variables

This package provides no configuration variables.
