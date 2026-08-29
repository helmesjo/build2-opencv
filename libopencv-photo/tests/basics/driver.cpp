#include <opencv2/photo.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  cv::Mat src = cv::Mat::zeros (16, 16, CV_8UC3);
  cv::Mat mask = cv::Mat::zeros (16, 16, CV_8UC1);
  mask (cv::Rect (6, 6, 4, 4)).setTo (255);

  cv::Mat dst;
  cv::inpaint (src, mask, dst, 3, cv::INPAINT_TELEA);

  assert (dst.rows == 16);
  assert (dst.cols == 16);
  assert (dst.type () == CV_8UC3);
}
