#include <queuelstpr/queuelstpr.hpp>
#include <stdexcept>

bool QueueLstPr::IsEmpty() const noexcept {
  return nullptr == head_;
}

QueueLstPr::QueueLstPr(QueueLstPr&& other)
  : head_(other.head_), tail_(other.tail_), size_(other.size_) {
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& other) {
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

void QueueLstPr::Pop() noexcept {
  if (!IsEmpty()) {
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
    if (head_ == nullptr)
      tail_ = nullptr;  

    size_--;
  }
}

void QueueLstPr::Push(const float& value) {
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


float& QueueLstPr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

const float& QueueLstPr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}


void QueueLstPr::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
  tail_ = nullptr;
  size_ = 0;
}