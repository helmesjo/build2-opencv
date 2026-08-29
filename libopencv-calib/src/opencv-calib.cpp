#include <opencv2/opencv-calib.hpp>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace opencv_calib
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
