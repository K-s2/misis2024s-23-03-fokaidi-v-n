#include "StackArr.hpp"

StackArr::StackArr(int size) {
  capacity = size;
  top = -1;
  data_ = new Complex[size];
}

StackArr::~StackArr() {
  delete[] data_;
}

void StackArr::push(Complex element) {
  if (isFull()) {
    std::cout << "Stack is full. Cannot push element." << std::endl;
    return;
  }
  data_[++top] = element;
}

Complex StackArr::pop() {
  if (isEmpty()) {
    std::cout << "Stack is empty. Cannot pop element." << std::endl;
    return Complex(); // Возвращаем пустой объект Complex
  }
  return data_[top--];
}

bool StackArr::isEmpty() {
  return top == -1;
}

bool StackArr::isFull() {
  return top == capacity - 1;
}

