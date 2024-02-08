#include "StackArr.hpp"

StackArr::StackArr(std::ptrdiff_t size) {
  capacity = size;
  this->size = 0;
  data_ = new Complex[capacity];
}

StackArr::StackArr(const StackArr& other) {
  capacity = other.capacity;
  size = other.size;
  data_ = new Complex[capacity];
  for (std::ptrdiff_t i = 0; i < size; ++i) {
    data_[i] = other.data_[i];
  }
}

StackArr::~StackArr() {
  delete[] data_;
}

void StackArr::push(Complex element) {
  if (isFull()) {
    capacity += 10;
    size += 10;
  }
  data_[size++] = element;
}

void StackArr::pop() {
  if (isEmpty()) {
    throw std::runtime_error("Stack is empty. Cannot pop element.");
  }
  return data_[--size];
}

Complex StackArr::top() {
  Complex top_{};
  if (isEmpty()) {
    throw std::runtime_error("Stack is empty. Cannot get top element.");
  }
  return top_->data_;
}

bool StackArr::isEmpty() {
  return size == 0;
}

bool StackArr::isFull() {
  return size == capacity;
}

StackArr& StackArr::operator=(const StackArr& other) {
  if (this == &other) {
    return *this;
  }

  delete[] data_;

  capacity = other.capacity;
  size = other.size;
  data_ = new Complex[capacity];

  for (std::ptrdiff_t i = 0; i < size; ++i) {
    data_[i] = other.data_[i];
  }

  return *this;
}
