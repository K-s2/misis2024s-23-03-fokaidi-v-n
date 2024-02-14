#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>

TEST_CASE("Tsmpty function") {
  StackLst arr;
  Complex x{ 2, 3 };
  CHECK((arr.IsEmpty() == 1));
}

TEST_CASE("push function") {
  StackLst arr;
  Complex x{ 2, 3 };
  arr.Push(x);
  CHECK((arr.IsEmpty() == 0));
  CHECK((arr.Top() == x));
}

TEST_CASE("Pop function") {
  StackLst arr;
  Complex x{ 2, 3 };
  arr.Push(x);
  CHECK((arr.IsEmpty() == 0));
  CHECK((arr.Top() == x));
  Complex y{ 3, 4 };
  arr.Push(y);
  CHECK((arr.Top() == y));
  arr.Pop();
  CHECK((arr.Top() == x));
}
