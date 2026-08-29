# libopencv-core - A C++ library

This is a `build2` package for the [`core`](https://github.com/opencv/opencv/tree/5.0.0/modules/core)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library. The
core module is the backbone of OpenCV, offering fundamental data structures,
matrix operations, and utility functions that other modules depend on. It's
essential for handling image data, performing mathematical computations, and
managing memory efficiently within the OpenCV ecosystem.


## Usage

To start using `libopencv-core` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-core ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-core%lib{opencv-core}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-core}
```

`lib{opencv-core}` is the OpenCV core module: `Mat`/`UMat` and the other core
data structures, matrix and array operations, XML/YAML/JSON persistence, and
common utilities (logging, threading, CPU feature detection, file system).


## Configuration variables

This package provides no configuration variables.
