#pragma once
#ifndef QUEUELST_QUEUELST_HPP_20240220
#define QUEUELST_QUEUELST_HPP_20240220

#include <cstddef>

template <typename T>
class QueueLstT final {
public:
  QueueLstT() = default;

  QueueLstT(const QueueLstT& src);

  QueueLstT(QueueLstT&& src) noexcept;

  ~QueueLstT() = default;

  QueueLstT& operator=(const QueueLstT& src);

  QueueLstT& operator=(QueueLstT&& src) noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const T& val);

  [[nodiscard]] T& Top();

  [[nodiscard]] const T& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    T val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

template <typename T>
QueueLstT<T>::QueueLstT(const QueueLstT& src) {
  if (!src.IsEmpty()) {
    head_ = new Node{ src.head_->val };
    Node* p_src = src.head_;
    Node* p_dst = head_;
    while (p_src->next) {
      p_dst->next = new Node{ p_src->next->val };
      p_src = p_src->next;
      p_dst = p_dst->next;
    }
    tail_ = p_dst;
  }
}

template <typename T>
QueueLstT<T>::QueueLstT(QueueLstT&& src) noexcept
  : head_(src.head_), tail_(src.tail_) {
  src.head_ = nullptr;
  src.tail_ = nullptr;
}


template <class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT&& other) {
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
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT& src) {
  if (this != &src) {
    if (src.IsEmpty()) {
      Clear();
    }
    else {
      // TODO: faster and smartert
      QueueLst copy(src);
      std::swap(head_, copy.head_);
      std::swap(tail_, copy.tail_);
    }
  }
  return *this;
}

template <typename T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT&& src) noexcept {
  if (this != &src) {
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
  }
  return *this;
}

template <typename T>
bool QueueLstT<T>::IsEmpty() const noexcept {
  return nullptr == head_;
}

template <typename T>
void QueueLstT<T>::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;
    head_ = head_->next;
    delete deleted;
  }
  if (IsEmpty()) {
    tail_ = nullptr;
  }
}

template <typename T>
void QueueLstT<T>::Push(const T& val) {
  if (IsEmpty()) {
    tail_ = new Node{ val };
    head_ = tail_;
  }
  else {
    tail_->next = new Node{ val };
    tail_ = tail_->next;
  }
}

template <typename T>
T& QueueLstT<T>::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top from empty queue.");
  }
  return head_->val;
}

template <typename T>
const T& QueueLstT<T>::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top from empty queue.");
  }
  return head_->val;
}

template <typename T>
void QueueLstT<T>::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}

template <typename T>
QueueLstT<T>::QueueLstT(QueueLstT&& src) noexcept :
  head_(src.head_), tail_(src.tail_) {
  src.head_ = nullptr;
  src.tail_ = nullptr;
}


#endif