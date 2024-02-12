#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>


TEST_CASE("Top function") {
  StackArr arr;
  Complex x{2, 3};
  arr.push(x);
  CHECK((arr.top() == x));
}

TEST_CASE("Empty function") {
  StackArr arr;
  Complex x{ 2, 3 };
  arr.push(x);
  CHECK((arr.isEmpty() == 0));
}

TEST_CASE("Empty function") {
  StackArr arr;
  Complex x{ 2, 3 };
  arr.push(x);
  arr.pop();
  CHECK((arr.isEmpty() == 1));
}