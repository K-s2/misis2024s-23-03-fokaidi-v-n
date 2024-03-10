#ifndef DYNARR_MISIS2023F_23_32
#define DYNARR_MISIS2023F_23_32

#include <cstddef>

class DynArr {
public:
  DynArr() { capacity_ = 10; size_ = 0; mass_ = new float[10]; };
  DynArr(DynArr&& other);
  DynArr(const DynArr& rhs);
  DynArr(const std::ptrdiff_t size);
  ~DynArr();

  DynArr& operator= (const DynArr& rhs);
  DynArr& operator=(DynArr&& other);
  void Resize(const std::ptrdiff_t size);

  float& operator[](const std::ptrdiff_t ind);
  const float& operator[](const std::ptrdiff_t ind) const;

  std::ptrdiff_t Size() const { return size_; }
  std::ptrdiff_t Capacity() const { return capacity_; }
private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 10;
  float* mass_;
};

#endif
