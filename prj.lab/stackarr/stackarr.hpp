#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class StackArr {
private:
  std::ptrdiff_t capacity_;
  std::ptrdiff_t size_;
  Complex* data_;

public:
  StackArr(std::ptrdiff_t size = 10);
  StackArr(const StackArr& other);
  ~StackArr();

  void push(Complex element);
  void pop();
  Complex top();
  bool isEmpty();
  bool isFull();

  StackArr& operator=(const StackArr& other);
};

#endif
