#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queuelst/queuelst.hpp"
#include "doctest.h""
#include <complex/complex.hpp>


TEST_CASE("TsEmpty function") {
  QueueLst q;
  Complex z{ 2, 3 };
  CHECK((q.IsEmpty() == 1));
}


TEST_CASE("push function") {
  QueueLst q;
  Complex x{ 2, 3 };
  q.Push(x);
  CHECK((q.IsEmpty() == 0));
  CHECK((q.Top() == x));
}