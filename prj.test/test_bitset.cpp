
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <bitset/bitset.hpp>
#include "doctest.h"


TEST_CASE("Fill") {
  BitSet b(3);
  b.Fill(1);
  CHECK((b.Size() == 3));
  CHECK((b.Get(2) == 1));
}

TEST_CASE("Fill and constructor") {
  BitSet b(2);
  CHECK((b.Size() == 2));
  BitSet c(33);
  CHECK((c.Size() == 33));
}


TEST_CASE("Get") {
  BitSet b(2);
  CHECK((b.Size() == 2));
  BitSet c(33);
  CHECK((b.Get(0) == 0));
  CHECK((c.Get(32) == 0));
}


TEST_CASE("Set") {
  BitSet b(2);
  CHECK((b.Size() == 2));
  BitSet c(33);
  b.Set(0, 1);
  CHECK((b.Get(0) == 1));
}

