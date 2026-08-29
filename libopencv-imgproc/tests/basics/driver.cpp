#include <opencv2/imgproc.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Basic image processing function.
  //
  cv::Mat bgr (2, 2, CV_8UC3, cv::Scalar (0, 0, 255));
  cv::Mat gray;
  cv::cvtColor (bgr, gray, cv::COLOR_BGR2GRAY);
  assert (gray.at<unsigned char> (0, 0) > 0);

  // putText exercises the (unbundled) stb_truetype font rasterizer and
  // the zlib-decompressed builtin font blobs end-to-end, not just link.
  //
  cv::Mat canvas = cv::Mat::zeros (30, 100, CV_8UC1);
  cv::putText (canvas, "Hi", cv::Point (5, 20), cv::FONT_HERSHEY_SIMPLEX,
               1.0, cv::Scalar (255));
  assert (cv::countNonZero (canvas) > 0);
}
