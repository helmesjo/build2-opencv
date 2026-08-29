#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Generate an ArUco marker and detect it back (a plain non-inline
  // exported class and function).
  //
  cv::aruco::Dictionary dict =
    cv::aruco::getPredefinedDictionary (cv::aruco::DICT_4X4_50);

  cv::Mat marker;
  dict.generateImageMarker (0, 200, marker);

  // Detection needs a quiet white margin around the marker.
  //
  cv::Mat padded;
  cv::copyMakeBorder (marker, padded, 50, 50, 50, 50,
                       cv::BORDER_CONSTANT, cv::Scalar (255));

  cv::aruco::ArucoDetector detector (dict);
  std::vector<std::vector<cv::Point2f>> corners;
  std::vector<int> ids;
  detector.detectMarkers (padded, corners, ids);

  assert (ids.size () == 1);
  assert (ids[0] == 0);
}
