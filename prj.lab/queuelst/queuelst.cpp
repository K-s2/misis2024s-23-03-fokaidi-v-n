
#include <queuelst/queuelst.hpp>

#include <stdexcept>

bool QueueLst::IsEmpty() const noexcept {
  return nullptr == head_;
}

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;
    head_ = head_->next;
    delete deleted;
  }
  if (IsEmpty()) {
    tail_ = nullptr;
  }
}

void QueueLst::Push(const Complex& val) {
  if (IsEmpty()) {
    new Node{ val, tail_ };
    head_ = tail_;
  }
  else {
    Node* y = new Node(val, head_);
    head_ = y;
    tail_ = tail_->next;
  }
}

Complex& QueueLst::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

const Complex& QueueLst::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

void QueueLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}