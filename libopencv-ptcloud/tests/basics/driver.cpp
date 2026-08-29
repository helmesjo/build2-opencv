#include <opencv2/ptcloud.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  cv::Ptr<cv::Octree> o (
    cv::Octree::createWithDepth (4, 2.0, cv::Point3f (0, 0, 0)));

  assert (o->empty ());
  assert (o->insertPoint (cv::Point3f (0.1f, 0.1f, 0.1f)));
  assert (!o->empty ());
  assert (o->isPointInBound (cv::Point3f (0.1f, 0.1f, 0.1f)));
}
