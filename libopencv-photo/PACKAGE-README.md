# libopencv-photo - A C++ library

This is a `build2` package for the [`photo`](https://github.com/opencv/opencv/tree/5.0.0/modules/photo)
module of the [`OpenCV`](https://github.com/opencv/opencv) C++ library.
It provides computational photography: inpainting, denoising, HDR imaging,
and seamless cloning/blending algorithms.


## Usage

To start using `libopencv-photo` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libopencv-photo ^5.0.0
```

Then import the library in your `buildfile`:

```
import libs = libopencv-photo%lib{opencv-photo}
```


## Importable targets

This package provides the following importable targets:

```
lib{opencv-photo}
```

`lib{opencv-photo}` is the OpenCV photo module: inpainting, denoising, HDR
imaging, and seamless cloning/blending.


## Configuration variables

This package provides no configuration variables.
