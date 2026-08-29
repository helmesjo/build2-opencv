#include <opencv2/flann.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  float data[][2] = {{0, 0}, {10, 10}, {20, 20}};
  cv::Mat features (3, 2, CV_32F, data);

  cv::flann::Index index (features, cv::flann::LinearIndexParams ());

  float query_data[] = {9, 9};
  cv::Mat query (1, 2, CV_32F, query_data);
  cv::Mat indices, dists;
  index.knnSearch (query, indices, dists, 1);

  assert (indices.at<int> (0) == 1);
}
