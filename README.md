# build2-opencv - OpenCV

This is a `build2` package repository for [`OpenCV`](https://github.com/opencv/opencv),
the open source computer vision and machine learning software library. OpenCV
is split into modules; this repository packages them individually. Packaged
so far: `libopencv-core`, `libopencv-flann`, `libopencv-geometry`,
`libopencv-imgproc`, `libopencv-stereo`, `libopencv-ptcloud`,
`libopencv-photo`, `libopencv-imgcodecs`.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use one
of these packages in your `build2`-based project, then instead see its
accompanying `PACKAGE-README.md` file (e.g.
[`libopencv-core/PACKAGE-README.md`](libopencv-core/PACKAGE-README.md)).

The development setup for `build2-opencv` uses the standard `bdep`-based workflow.
For example:

```
git clone .../build2-opencv.git
cd build2-opencv

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
