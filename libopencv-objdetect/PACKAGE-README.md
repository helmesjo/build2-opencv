# libopencv-objdetect - A C++ library

This is a `build2` package for the [`objdetect`](https://github.com/opencv/opencv/tree/5.0.0/modules/objdetect)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. It
provides object detection: ArUco/ChArUco marker and board detection, QR
code and barcode detection and decoding, chessboard/circles-grid
calibration pattern detection, and the classic Haar/LBP cascade classifier.


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
pattern detection. The DNN-based face detection and recognition
(`FaceDetectorYN`, `FaceRecognizerSF`) and the MCC color-checker's
DNN-assisted mode are not available, since this package does not depend
on the (not yet packaged) dnn module. Barcode detection's optional
super-resolution preprocessing falls back to plain resizing under the
same condition.


## Configuration variables

This package provides no configuration variables.
