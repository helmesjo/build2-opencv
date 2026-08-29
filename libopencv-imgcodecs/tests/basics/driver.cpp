#include <opencv2/imgcodecs.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // BMP needs no external codec library, so this exercises the
  // in-memory encode/decode round trip without any optional backend.
  //
  cv::Mat src = cv::Mat::zeros (8, 8, CV_8UC3);
  src.setTo (cv::Scalar (10, 20, 30));

  std::vector<uchar> buf;
  bool ok = cv::imencode (".bmp", src, buf);
  assert (ok);
  assert (!buf.empty ());

  cv::Mat dst = cv::imdecode (buf, cv::IMREAD_COLOR);
  assert (dst.rows == 8);
  assert (dst.cols == 8);
  assert (dst.type () == CV_8UC3);
}
