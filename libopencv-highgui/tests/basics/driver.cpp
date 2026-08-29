#include <opencv2/highgui.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // No GUI toolkit backend (Qt/GTK/Win32/Cocoa/Wayland/framebuffer) is
  // available in this build - a standard, fully-supported "headless
  // OpenCV" configuration. Every windowing function still exists in the
  // public API but throws a well-defined cv::Exception at call time
  // (upstream's own CV_NO_GUI_ERROR fallback), rather than failing to
  // link or behaving unpredictably. Verify exactly that.
  //
  bool threw = false;
  try
  {
    cv::namedWindow ("smoke");
  }
  catch (const cv::Exception& e)
  {
    threw = true;
    assert (e.code == cv::Error::StsError);
  }

  assert (threw);
}
