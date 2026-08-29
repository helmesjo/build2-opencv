#include <opencv2/opencv-flann.hpp>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace opencv_flann
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
