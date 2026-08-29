# libopencv-video - A C++ library

This is a `build2` package for the [`video`](https://github.com/opencv/opencv/tree/5.0.0/modules/video)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides video analysis: motion analysis (optical flow, background
subtraction) and object tracking.


## Usage

To start using `libopencv-video` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-video ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-video%lib{opencv-video}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-video}
```

`lib{opencv-video}` is the OpenCV video module: optical flow, background
subtraction, and object tracking. The DNN-based trackers (NanoTrack,
DaSiamRPN, VIT) are not available, since this package does not depend on
the (not yet packaged) dnn module.


## Configuration variables

This package provides no configuration variables.
