# libopencv-highgui - A C++ library

This is a `build2` package for the [`highgui`](https://github.com/opencv/opencv/tree/5.0.0/modules/highgui)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
provides simple window display and UI controls (`cv::imshow`,
`cv::waitKey`, trackbars, mouse callbacks). This baseline build has no GUI
toolkit backend (Qt, GTK, Win32, Cocoa, Wayland) compiled in, which is a
standard, fully-supported "headless OpenCV" configuration: every
windowing function still exists in the public API but throws a
`cv::Exception` at call time instead of failing to link.


## Usage

To start using `libopencv-highgui` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-highgui ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-highgui%lib{opencv-highgui}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-highgui}
```

`lib{opencv-highgui}` is the OpenCV highgui module: window display and UI
controls.


## Configuration variables

This package provides no configuration variables.
