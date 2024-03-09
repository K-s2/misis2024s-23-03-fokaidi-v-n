#include <queuelst/queuelst.hpp>
#include <stdexcept>

QueueLst::QueueLst(const QueueLst& other) {
  if (other.head_ != nullptr) {
    head_ = new Node(other.head_->val, nullptr);
    Node* a = head_;
    Node* b = other.head_-> next;
    while (b != nullptr) {
      Node* tmp = new Node(b->val, nullptr);
      a->next = tmp;
      a = tmp;
      b = b->next;
    }
    tail_ = a;
    size_ = other.size_;
  }
}

QueueLst::~QueueLst() {
  while (head_ != nullptr) {
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
  }
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
  if (rhs.head_ != nullptr) {
    Node* a = head_;
    if (a == nullptr)
    {
      a = new Node(Complex(), nullptr);
      head_ = a;
      tail_ = a;
    }
    Node* b = rhs.head_;
    while (b != rhs.tail_) {
      if (a == tail_)
      {
        a->next = new Node(Complex(), nullptr);
        tail_ = a->next;
      }
      a->val = b->val;
      a = a->next;
      b = b->next;
    }
    a->val = b->val;
    while (a->next != nullptr)
    {
      Node* tmp = a->next;
      a->next = a->next->next;
      delete tmp;
    }
    tail_ = a;
  }
  else {
    while (head_ != nullptr) {
      Node* tmp = head_->next;
      delete head_;
      head_ = tmp;
    }
    tail_ = nullptr;
  }
  size_ = rhs.size_;
  return *this;
}

bool QueueLst::IsEmpty() const noexcept {
  return head_ == nullptr;
}

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
    if (head_ == nullptr)
      tail_ = nullptr;

    size_--;
  }
}

void QueueLst::Push(const Complex& val) {
  if (tail_ == nullptr)
  {
    tail_ = new Node(val, nullptr);
    head_ = tail_;
    size_ = 1;
  }
  else
  {
    tail_->next = new Node(val, nullptr);
    tail_ = tail_->next;
    ++size_;
  }
}

Complex& QueueLst::Top() {
  if (head_ == nullptr)
    throw std::out_of_range("Queue is empty");

  return head_->val;
}

const Complex& QueueLst::Top() const {
  if (head_ == nullptr)
    throw std::out_of_range("Queue is empty");

  return head_->val;
}

void QueueLst::Clear() noexcept {
  while (head_ != nullptr) {
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
  }
  tail_ = nullptr;
  size_ = 0;
}