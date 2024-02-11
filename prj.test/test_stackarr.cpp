#include "doctest.h"
#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>


TEST_CASE("Top function") {
  StackArr arr;
  Complex x{2, 3};
  arr.push(x);
  CHECK(arr.top() == x);
}