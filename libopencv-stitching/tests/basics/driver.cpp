#include <opencv2/stitching.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Construct a Stitcher via its non-inline exported factory function.
  //
  cv::Ptr<cv::Stitcher> stitcher (cv::Stitcher::create (cv::Stitcher::PANORAMA));
  assert (stitcher != nullptr);
}
