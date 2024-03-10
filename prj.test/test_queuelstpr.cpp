#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "queuelstpr/queuelstpr.hpp"
#include "doctest.h""

TEST_CASE("IsEmpty function") {
  QueueLstPr q;
  float x{ 3 };
  CHECK(q.IsEmpty());
}

TEST_CASE("Push function") {
  QueueLstPr q;
  float x{ 2 };
  q.Push(x);
  CHECK_FALSE(q.IsEmpty());
  CHECK(q.Top() == x);
}

TEST_CASE("Priority") {
  QueueLstPr q;
  float x{ 2 };
  q.Push(x);
  CHECK_FALSE(q.IsEmpty());
  CHECK(q.Top() == x);
  float y{ 1 };
  q.Push(y);
  CHECK(q.Top() == y);
  float z{ 4 };
  q.Push(z);
  CHECK(q.Top() == y);
}
