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

TEST_CASE("Move constructor") {
  QueueLst q1;
  Complex x{ 2, 3 };
  q1.Push(x);

  QueueLst q2(std::move(q1));

  CHECK((q1.IsEmpty() == 1)); // ���������, ��� q1 ���� ������
  CHECK((q2.IsEmpty() == 0)); // ���������, ��� q2 �������� ������
  CHECK((q2.Top() == x)); // ���������, ��� ������ ���� ���������� ���������
}

TEST_CASE("Move assignment operator") {
  QueueLst q1;
  Complex x{ 2, 3 };
  q1.Push(x);

  QueueLst q2;
  Complex y{ 4, 5 };
  q2.Push(y);

  q2 = std::move(q1);

  CHECK((q1.IsEmpty() == 1)); // ���������, ��� q1 ���� ������
  CHECK((q2.IsEmpty() == 0)); // ���������, ��� q2 �������� ������
  CHECK((q2.Top() == x)); // ���������, ��� ������ ���� ���������� ���������
}