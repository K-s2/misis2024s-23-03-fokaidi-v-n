#include <stackarrt/stackarrt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cstdint>
#include <string>

TEST_CASE("[stacklstt] - ctor") {
  StackArrT<float> stf;
  StackArrT<int> sti;
  StackArrT<std::string> sts;
  int a = 3;
  sti.Push(a);
  CHECK(sti.Top() == a);
  std::string s = "hfhfhhf";
  sts.Push(s);
  CHECK(sts.Top() == s);
}
