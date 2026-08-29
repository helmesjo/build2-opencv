# libopencv-ptcloud - A C++ library

This is a `build2` package for the [`ptcloud`](https://github.com/opencv/opencv/tree/5.0.0/modules/ptcloud)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides high level point cloud and mesh operations.


## Usage

To start using `libopencv-ptcloud` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-ptcloud ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-ptcloud%lib{opencv-ptcloud}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-ptcloud}
```

`lib{opencv-ptcloud}` is the OpenCV ptcloud module: point cloud and mesh
operations.


## Configuration variables

This package provides no configuration variables.
