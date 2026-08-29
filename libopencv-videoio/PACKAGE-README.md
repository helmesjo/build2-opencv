# libopencv-videoio - A C++ library

This is a `build2` package for the [`videoio`](https://github.com/opencv/opencv/tree/5.0.0/modules/videoio)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
reads and writes video, image sequences, and camera streams through
`cv::VideoCapture`/`cv::VideoWriter`. This baseline build has every
external capture/encode backend (V4L, FFmpeg, GStreamer, DirectShow,
Media Foundation, AVFoundation, and others) off, leaving the built-in
image-sequence (`CAP_IMAGES`) and MJPEG/AVI container
(`CAP_OPENCV_MJPEG`) support, which need no external library.


## Usage

To start using `libopencv-videoio` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-videoio ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-videoio%lib{opencv-videoio}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-videoio}
```

`lib{opencv-videoio}` is the OpenCV videoio module: video/image-sequence
capture and writing.


## Configuration variables

This package provides no configuration variables.
