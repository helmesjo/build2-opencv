// Sample/test data file search path configuration.
//
// OPENCV_INSTALL_PREFIX, OPENCV_DATA_INSTALL_PATH, and
// OPENCV_INSTALL_DATA_DIR_RELATIVE are all guarded at their use site
// (opencv2/core/utils/datafile.cpp) and are intentionally left undefined:
// this package does not install or bundle OpenCV's separate sample-data
// set. OPENCV_BUILD_DIR and OPENCV_DATA_BUILD_DIR_SEARCH_PATHS are used
// unconditionally there, so they still need a (harmless) value.
//
#define OPENCV_BUILD_DIR "."

#define OPENCV_DATA_BUILD_DIR_SEARCH_PATHS \
    "./"
