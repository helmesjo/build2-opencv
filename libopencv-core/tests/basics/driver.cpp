#include <opencv2/core.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Basic Mat construction and a dispatched arithmetic function.
  //
  cv::Mat m = cv::Mat::ones (3, 3, CV_32F);
  assert (cv::sum (m)[0] == 9.0);

  // A plain non-inline exported function.
  //
  assert (!cv::getBuildInformation ().empty ());
}
