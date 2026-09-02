# libopencv-ptcloud-tests - High level point cloud and mesh operations (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `ptcloud` module.
Only `test_octree.cpp`, `test_tsdf.cpp`, `test_registration.cpp`, and
`test_main.cpp` are covered: `test_normal.cpp`, `test_odometry.cpp`,
`test_pointcloud_io.cpp`, `test_pose_graph.cpp`, and `test_rendering.cpp`
are excluded, since (most of) their test cases read fixture files (RGBD
images, `.g2o` pose graphs, `.obj`/`.ply` point clouds) from the separate
`opencv_extra` test-data repository, which this repository does not fetch.
`test_tsdf.cpp` calls `imshow`/`waitKey` directly without including
`opencv2/highgui.hpp` itself, relying on `libopencv-ts`'s upstream umbrella
header to supply it transitively; since this package's `libopencv-ts`
depends only on core and imgproc, the file is patched with the missing
include, and this package depends on `libopencv-highgui` directly.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
