#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <cstdio>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Round-trip a tiny image sequence through the built-in CAP_IMAGES
  // backend as PPM frames (no external codec needed - unlike JPEG/PNG/etc,
  // PXM is part of imgcodecs' built-in support), exercising real
  // non-inline exported code. Note: the built-in CAP_OPENCV_MJPEG/AVI
  // backend also exists but its reader decodes frames via imgcodecs'
  // JPEG support, which this baseline build does not have (HAVE_JPEG is
  // off, shared from libopencv-core's cvconfig.h) - PPM avoids that.
  //
  const char* path = "smoke_%02d.ppm";

  cv::Mat frame = cv::Mat::zeros (48, 64, CV_8UC3);
  cv::rectangle (frame, cv::Rect (8, 8, 32, 32), cv::Scalar (0, 0, 255), -1);

  {
    cv::VideoWriter writer (path, 0, 10, cv::Size (64, 48));
    assert (writer.isOpened ());
    writer.write (frame);
    writer.release ();
  }

  {
    cv::VideoCapture reader (path, cv::CAP_IMAGES);
    assert (reader.isOpened ());

    cv::Mat read_back;
    assert (reader.read (read_back));
    assert (read_back.size () == frame.size ());
  }

  std::remove ("smoke_00.ppm");
}
