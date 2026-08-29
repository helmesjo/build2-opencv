#include <opencv2/features.hpp>
#include <opencv2/imgproc.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // A synthetic checkerboard image (rich in corners), detected with ORB
  // (a plain non-inline exported class).
  //
  cv::Mat m = cv::Mat::zeros (256, 256, CV_8UC1);
  for (int y = 0; y < 16; ++y)
    for (int x = 0; x < 16; ++x)
      if ((x + y) % 2 == 0)
        cv::rectangle (m, cv::Rect (x * 16, y * 16, 16, 16), cv::Scalar (255), -1);

  cv::Ptr<cv::ORB> orb = cv::ORB::create ();
  std::vector<cv::KeyPoint> kps;
  orb->detect (m, kps);

  assert (!kps.empty ());
}
