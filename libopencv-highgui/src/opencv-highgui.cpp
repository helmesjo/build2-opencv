#include <opencv2/opencv-highgui.hpp>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace opencv_highgui
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
