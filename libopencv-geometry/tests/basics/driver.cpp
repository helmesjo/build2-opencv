#include <opencv2/geometry.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  std::vector<cv::Point2f> square {
    {0, 0}, {10, 0}, {10, 10}, {0, 10}
  };

  assert (cv::contourArea (square) == 100.0);
  assert (cv::isContourConvex (square));
}
