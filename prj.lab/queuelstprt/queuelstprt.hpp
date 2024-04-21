#pragma once
#ifndef QUEUELST_QUEUELST_HPP_20240220
#define QUEUELST_QUEUELST_HPP_20240220


#include <cstddef>

template <class T>
class QueLstPrT {
public:
  QueLstPrT() = default;

  QueLstPrT(const QueLstPrT<T>&) = default;

  ~QueLstPrT() = default;

  [[nodiscard]] QueLstPrT<T>& operator=(const QueLstPrT<T>&) = default;

  [[nodiscard]] bool IsEmpty() const noexcept;

  [[nodiscard]] QueLstPrT<T>& operator=(QueLstPrT<T>&&);

  QueLstPrT(QueLstPrT<T>&&);

  void Pop() noexcept;

  void Push(const T& val);

  [[nodiscard]] T& Top();

  [[nodiscard]] const T& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Node(T v_, Node* n) { val = v_; next = n; }
    T val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  int size_ = 0;
};

template <class T>
bool QueLstPrT<T>::IsEmpty() const noexcept {
  return nullptr == head_;
}

template <class T>
QueLstPrT<T>::QueLstPrT(QueLstPrT<T>&& other) : head_(other.head_), tail_(other.tail_), size_(other.size_) {
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
}

template <class T>
QueLstPrT<T>& QueLstPrT<T>::operator=(QueLstPrT<T>&& other) {
  if (this != &other) {
    Clear();
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <class T>
void QueLstPrT<T>::Pop() noexcept {
  if (!IsEmpty()) {
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
    if (head_ == nullptr)
      tail_ = nullptr;

    size_--;
  }
}

template <class T>
void QueLstPrT<T>::Push(const T& value) {
  Node* newNode = new Node(value, nullptr);
  if (!head_ || value < head_->val) {
    newNode->next = head_;
    head_ = newNode;
  }
  else {
    Node* current = head_;
    while (current->next && value >= current->next->val) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
  if (!tail_) {
    tail_ = newNode;
  }
}

template <class T>
T& QueLstPrT<T>::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

template <class T>
const T& QueLstPrT<T>::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

template <class T>
void QueLstPrT<T>::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
  tail_ = nullptr;
  size_ = 0;
}


#endif