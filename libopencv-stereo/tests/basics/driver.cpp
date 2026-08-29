#include <opencv2/stereo.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Keep this self-contained (core operations only): stereo depends on
  // imgproc as an implementation detail, not an interface dependency, so
  // this test executable does not import libopencv-imgproc.
  //
  cv::Mat left = cv::Mat::zeros (64, 64, CV_8UC1);
  cv::Mat right = cv::Mat::zeros (64, 64, CV_8UC1);
  left (cv::Rect (10, 10, 20, 20)).setTo (255);
  right (cv::Rect (14, 10, 20, 20)).setTo (255);

  cv::Ptr<cv::StereoBM> m (cv::StereoBM::create (16, 21));
  cv::Mat disparity;
  m->compute (left, right, disparity);

  assert (disparity.rows == 64);
  assert (disparity.cols == 64);
}
