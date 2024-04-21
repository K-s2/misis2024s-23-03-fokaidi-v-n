#ifndef DYNARR_MISIS2023F_23_32
#define DYNARR_MISIS2023F_23_32

#include <cstddef>

template <typename T>
class DynArrT {
public:
  DynArrT() { capacity_ = 10; size_ = 0; mass_ = new T[10]; };
  DynArrT(DynArrT<T>&& other);
  DynArrT(const DynArrT<T>& rhs);
  DynArrT(const std::ptrdiff_t size);
  ~DynArrT();

  DynArrT<T>& operator= (const DynArrT<T>& rhs);
  DynArrT<T>& operator=(DynArrT<T>&& other);
  void Resize(const std::ptrdiff_t size);

  T& operator[](const std::ptrdiff_t ind);
  const T& operator[](const std::ptrdiff_t ind) const;

  std::ptrdiff_t Size() const { return size_; }
  std::ptrdiff_t Capacity() const { return capacity_; }
private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 10;
  T* mass_;
};


template <class T>
DynArrT<T>::DynArrT<T>(DynArrT<T>&& other) : size_(other.size_), capacity_(other.capacity_), mass_(other.mass_) {
  other.size_ = 0;
  other.capacity_ = 0;
  other.mass_ = nullptr;
}

template <class T>
DynArrT<T>& DynArrT<T>::operator=(DynArrT<T>&& other) {
  if (this != &other) {
    delete[] mass_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    mass_ = other.mass_;

    other.size_ = 0;
    other.capacity_ = 0;
    other.mass_ = nullptr;
  }
  return *this;
}

template <class T>
DynArrT<T>::DynArrT<T>(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::runtime_error("It is impossible to create an array of this size");
  }
  else {
    size_ = size;
    capacity_ = (capacity_ > 2 * size_ ? capacity_ : 2 * size_);
    mass_ = new T[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      mass_[i] = 0;
    }
  }
}

template <class T>
DynArrT<T>::DynArrT<T>(const DynArrT<T>& rhs) {
  capacity_ = (capacity_ > 2 * rhs.size_ ? capacity_ : 2 * rhs.size_);
  size_ = rhs.size_;
  mass_ = new T[capacity_];
  for (std::ptrdiff_t i = 0; i < size_; ++i) {
    mass_[i] = rhs.mass_[i];
  }
}

template <class T>
DynArrT<T>::~DynArrT<T>() {
  delete[] mass_;
}

template <class T>
DynArrT<T>& DynArrT<T>::operator= (const DynArrT<T>& rhs) {
  if (rhs.size_ > capacity_ || 4 * rhs.size_ < capacity_) {
    capacity_ = 2 * rhs.size_;
    size_ = rhs.size_;
    delete[] mass_;
    mass_ = new T[capacity_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      mass_[i] = rhs.mass_[i];
    }
    return *this;
  }
  else {
    size_ = rhs.size_;
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
      mass_[i] = rhs.mass_[i];
    }
    return *this;
  }
}

template <class T>
void DynArrT<T>::Resize(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::runtime_error("It is impossible to resize an array of this size");
  }
  else {
    if (size > size_) {
      if (size > capacity_) {
        capacity_ = 2 * size;
        T* new_mass_ = new T[capacity_];
        for (std::ptrdiff_t i = 0; i < size_; ++i) {
          new_mass_[i] = mass_[i];
        }
        for (std::ptrdiff_t i = size_; i < size; ++i) {
          new_mass_[i] = 0;
        }
        size_ = size;
        delete[] mass_;
        mass_ = new_mass_;
      }
      else {
        for (std::ptrdiff_t i = size_; i < size; ++i) {
          mass_[i] = 0;
        }
        size_ = size;
      }
    }
    else {
      size_ = size;
    }
  }
}


template <class T>
T& DynArrT<T>::operator[] (const std::ptrdiff_t ind) {
  if (ind < 0 || ind >= size_) {
    throw std::runtime_error("Index out of range");
  }
  else {
    return mass_[ind];
  }
}

template <class T>
const T& DynArrT<T>::operator[](const std::ptrdiff_t ind) const {
  if (ind < 0 || ind >= size_) {
    throw std::runtime_error("Index out of range");
  }
  else {
    return mass_[ind];
  }
}
