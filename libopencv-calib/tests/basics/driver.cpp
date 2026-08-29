#include <opencv2/calib.hpp>

#undef NDEBUG
#include <cassert>
#include <vector>

int main ()
{
  // A simple planar point set, just enough to exercise a non-inline
  // exported calibration function.
  //
  std::vector<std::vector<cv::Point3f>> object_points (1);
  std::vector<std::vector<cv::Point2f>> image_points (1);

  for (int y (0); y != 4; ++y)
    for (int x (0); x != 4; ++x)
    {
      object_points[0].push_back (cv::Point3f (float (x), float (y), 0.0F));
      image_points[0].push_back (
        cv::Point2f (100.0F + float (x) * 50.0F, 100.0F + float (y) * 50.0F));
    }

  cv::Mat k (
    cv::initCameraMatrix2D (object_points, image_points, cv::Size (640, 480)));

  assert (k.rows == 3 && k.cols == 3);
  assert (k.at<double> (0, 0) > 0.0);
  assert (k.at<double> (1, 1) > 0.0);
}
