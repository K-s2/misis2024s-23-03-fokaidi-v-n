// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <cstddef>
#include <complex/complex.hpp>

class StackLst {
public:
  [[nodiscard]] StackLst() = default;

  [[nodiscard]] StackLst(const StackLst&) = default;

  ~StackLst() = default;

  [[nodiscard]] StackLst& operator=(const StackLst&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
};

#endif // !STACKARR_STACKARR_HPP_20240203