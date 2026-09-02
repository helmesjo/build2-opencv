#include <opencv2/ts.hpp>

#undef NDEBUG
#include <cassert>

int main (int argc, char** argv)
{
  // A non-inline exported singleton accessor, proving the library links,
  // plus a minimal gtest run (zero registered tests) proving the swapped-in
  // external gtest dependency is wired correctly.
  //
  cvtest::TS* ts (cvtest::TS::ptr ());
  assert (ts != nullptr);

  ::testing::InitGoogleTest (&argc, argv);
  assert (RUN_ALL_TESTS () == 0);
}
