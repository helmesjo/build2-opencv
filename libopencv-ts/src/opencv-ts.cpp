#include <opencv2/opencv-ts.hpp>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace opencv_ts
{
  void say_hello (ostream& o, const string& n)
  {
    if (n.empty ())
      throw invalid_argument ("empty name");

    o << "Hello, " << n << '!' << endl;
  }
}
