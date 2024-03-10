// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUELST_QUEUELST_HPP_20240220
#define QUEUELST_QUEUELST_HPP_20240220

#include <complex/complex.hpp>

#include <cstddef>

class QueueLstPr {
public:
  QueueLstPr() = default;

  QueueLstPr(const QueueLstPr&) = default;

  ~QueueLstPr() = default;

  [[nodiscard]] QueueLstPr& operator=(const QueueLstPr&) = default;

  [[nodiscard]] bool IsEmpty() const noexcept;
  [[nodiscard]] QueueLstPr& operator=(QueueLstPr&&);
  QueueLstPr(QueueLstPr&&);

  void Pop() noexcept;

  void Push(const float& val);

  [[nodiscard]] float& Top();

  [[nodiscard]] const float& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Node(float v_, Node* n) { val = v_; next = n; }
    float val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;   //!< 
  Node* tail_ = nullptr;
  int size_ = 0;//!< 
};

#endif