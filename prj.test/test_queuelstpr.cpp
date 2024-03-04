#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queuelstpr/queuelstpr.hpp"
#include "doctest.h""
#include <complex/complex.hpp>


TEST_CASE("TsEmpty function") {
  QueueLstPr q;
  float x{ 3 };
  CHECK((q.IsEmpty() == 1));
}


TEST_CASE("push function") {
  QueueLstPr q;
  float x{ 2 };
  q.Push(x);
  CHECK((q.IsEmpty() == 0));
  CHECK((q.Top() == x));
}

TEST_CASE("priority") {
  QueueLstPr q;
  float x{ 2 };
  q.Push(x);
  CHECK((q.IsEmpty() == 0));
  CHECK((q.Top() == x));
  float y{ 1 };
  q.Push(y);
  CHECK((q.Top() == y));
  float z{ 4 };
  q.Push(z);
  CHECK((q.Top() == y));
}