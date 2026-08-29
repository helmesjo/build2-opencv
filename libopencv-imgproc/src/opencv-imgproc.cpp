#include <opencv2/opencv-imgproc.hpp>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace opencv_imgproc
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
