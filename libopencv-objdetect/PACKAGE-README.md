# libopencv-objdetect - Object detection

This is a `build2` package for the [`objdetect`](https://github.com/opencv/opencv/tree/5.0.0/modules/objdetect)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
provides object detection: ArUco/ChArUco markers and boards, QR codes and
barcodes, chessboard/circles-grid calibration patterns, and the classic
Haar/LBP cascade classifier. DNN-based face detection and recognition
(`FaceDetectorYN`, `FaceRecognizerSF`) are not available, since this package
does not depend on the (not yet packaged) dnn module.


## Usage

To start using `libopencv-objdetect` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-objdetect ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-objdetect%lib{opencv-objdetect}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-objdetect}
```

`lib{opencv-objdetect}` is the OpenCV objdetect module: marker, code, and
pattern detection.


## Configuration variables

This package provides no configuration variables.
