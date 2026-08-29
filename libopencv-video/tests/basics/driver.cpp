#include <opencv2/video.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // A simple probability image and a non-inline exported tracking
  // function.
  //
  cv::Mat prob (cv::Mat::zeros (100, 100, CV_8UC1));
  prob (cv::Rect (40, 40, 20, 20)).setTo (255);

  cv::Rect window (30, 30, 40, 40);
  int iters (
    cv::meanShift (
      prob, window, cv::TermCriteria (cv::TermCriteria::MAX_ITER, 10, 1.0)));

  assert (iters >= 0);
  assert (window.width == 40 && window.height == 40);
}
