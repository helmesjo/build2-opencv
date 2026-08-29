# libopencv-features - Features framework

This is a `build2` package for the [`features`](https://github.com/opencv/opencv/tree/5.0.0/modules/features)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library (known
as `features2d` in OpenCV 4.x). It provides 2D feature detection, description,
and matching.


## Usage

To start using `libopencv-features` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-features ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-features%lib{opencv-features}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-features}
```

`lib{opencv-features}` is the OpenCV features module: feature detectors,
descriptors, and matchers. The `opencv2/features2d.hpp` header is a
compatibility alias for `opencv2/features.hpp`.


## Configuration variables

This package provides no configuration variables.
