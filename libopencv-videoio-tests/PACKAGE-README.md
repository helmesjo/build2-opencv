# libopencv-videoio-tests - Video I/O (tests)

This is a `build2` package containing the test suite for the
[`OpenCV`](https://github.com/opencv/opencv) library's `videoio` module.
`test_images.cpp` is excluded: its tests round-trip PNG image sequences,
and this project's `libopencv-imgcodecs` does not build PNG support (see
`libopencv-imgcodecs-tests/PACKAGE-README.md`). All other 12 non-OCL
upstream test files are covered (`test_v4l2.cpp` compiles to an
effectively empty translation unit: its whole body is wrapped in
`#ifdef HAVE_CAMV4L2`, never defined here).

Most kept tests gate on a specific backend (FFmpeg, GStreamer, MSMF,
Intel MFX, V4L2, ...) via `hasBackend()` before touching any file, and
this project builds none of them, so those tests cleanly skip rather
than needing test data. Four cases are excluded via `--gtest_filter`
since they need things this repository does not have:
- `AudioOpenCheck.bad_arg_invalid_audio_sample_per_second` opens a real
  (required) fixture file from the separate `opencv_extra` test-data
  repository without a backend gate first, so it would hard-fail rather
  than skip.
- `videoio_builtin.basic_avi` reads `video/big_buck_bunny.mjpg.avi`, an
  `opencv_extra` fixture, via the shared `BunnyParameters` test helper
  (in `test_precomp.hpp`) -- unlike the rest of `test_container_avi.cpp`,
  which self-generates or round-trips its own data.
- `videoio/videoio_synthetic.write_read_position` fails for both
  instantiated cases (MJPG via the built-in `CV_MJPEG` backend) in this
  environment; not a test-data issue, a real seek-accuracy gap in this
  environment/build's built-in MJPEG support.
- `videoio/videocapture_acceleration.read` needs a real encoded video
  fixture per codec (`video/sample_*.mp4`) from `opencv_extra`, for each
  of its roughly 100 backend/codec/acceleration parameter combinations.

`test_precomp.hpp`, `test_gstreamer.cpp`, `test_ffmpeg.cpp`, and
`test_video_io.cpp` are all unmodified: `opencv2/ts/ocl_test.hpp` and
`opencv2/imgcodecs.hpp` (for the latter three files' `imread`/`imwrite`
calls) are available from `libopencv-ts`, which matches upstream's own
`ts` module dependency list and header set.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
