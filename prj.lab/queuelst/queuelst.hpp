#pragma once
#ifndef QUEUELST_MISIS2023S_23_32
#define QUEUELST_MISIS2023S_23_32

#include <complex/complex.hpp>
#include <cstddef>

class QueueLst {
public:
  QueueLst() = default;

  QueueLst(const QueueLst&);

  ~QueueLst();

  [[nodiscard]] QueueLst& operator=(const QueueLst&);

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

  int Size() { return size_; }
private:
  struct Node {
    Node(const Complex& v, Node* n) : val(v), next(n) {}
    Complex val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  int size_ = 0;
};

#endif