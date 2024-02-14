#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>


TEST_CASE("Top function") {
  StackArr arr;
  Complex x{2, 3};
  arr.Push(x);
  CHECK((arr.Top() == x));
}

TEST_CASE("Empty function") {
  StackArr arr;
  Complex x{ 2, 3 };
  arr.Push(x);
  CHECK((arr.IsEmpty() == 0));
}

TEST_CASE("Empty function") {
  StackArr arr;
  Complex x{ 2, 3 };
  arr.Push(x);
  arr.Pop();
  CHECK((arr.IsEmpty() == 1));
}