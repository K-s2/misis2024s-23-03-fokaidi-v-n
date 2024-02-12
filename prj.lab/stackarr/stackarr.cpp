#include "StackArr.hpp"

StackArr::StackArr(std::ptrdiff_t size) {
  capacity_ = size;
  size_ = 0;
  data_ = new Complex[capacity_];
}

StackArr::StackArr(const StackArr& other) {
  capacity_ = other.capacity_;
  size_ = other.size_;
  data_ = new Complex[capacity_];
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

StackArr::~StackArr() {
  delete[] data_;
}

void StackArr::push(Complex element) {
  if (isFull()) {
    capacity_ += 10;
    size_ += 10;
  }
  data_[size_++] = element;
}

void StackArr::pop() noexcept {
  if (isEmpty()) {
    throw std::runtime_error("Stack is empty. Cannot pop element.");
  }
  Complex* new_data = new Complex[capacity_];
  for (int i = 0; i < size_ - 1; i++) {
    new_data[i] = data_[i];
  }
  delete[] data_;
  size_ -= 1;
  data_ = new_data;
  delete[] new_data;
}

Complex StackArr::top() {
  Complex top_{};
  if (isEmpty()) {
    throw std::runtime_error("Stack is empty. Cannot get top element.");
  }
  return data_[0];
}

bool StackArr::isEmpty() {
  return size_ == 0;
}

bool StackArr::isFull() {
  return size_ == capacity_;
}

StackArr& StackArr::operator=(const StackArr& other) {
  if (this == &other) {
    return *this;
  }

  delete[] data_;

  capacity_ = other.capacity_;
  size_ = other.size_;
  data_ = new Complex[capacity_];

  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }

  return *this;
}

