#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queuearr/queuearr.hpp"
#include "doctest.h""
#include <complex/complex.hpp>


TEST_CASE("TsEmpty function") {
  QueueArr q;
  Complex z{ 2, 3 };
  CHECK((q.IsEmpty() == 1));
}

TEST_CASE("push function") {
  QueueArr q;
  Complex x{ 2, 3 };
  q.Push(x);
  CHECK((q.IsEmpty() == 0));
  CHECK((q.Top() == x));
}