/*
 *      ** File generated automatically, do not modify **
 *
 * This file defines the list of modules available in current build configuration
 *
 *
*/

// This definition means that OpenCV is built with enabled non-free code.
// For example, patented algorithms for non-profit/non-commercial use only.
/* #undef OPENCV_ENABLE_NONFREE */

// HAVE_OPENCV_<MODULE> flags are supplied via a -D compiler option exported
// by each dependency's own build2 package (see that package's src/buildfile
// cxx.export.poptions), not defined in this file. This file only needs to
// exist so that the bare #include "opencv2/opencv_modules.hpp" used
// throughout OpenCV's own headers resolves. Defining the flags here instead
// would mean whichever dependency's copy of this file happens to win the
// #include search order silently wins for every package that imports it -
// this previously masked HAVE_OPENCV_FLANN for libopencv-stitching, since
// none of libopencv-core/-geometry/-imgproc/-features individually defined
// it (each shipped either no copy, or one listing only its own module).
