#include <bitset/bitset.hpp>
#include <stdexcept>


void BitSet::Fill(const bool val) noexcept {
  if (val) {
    for (int i = 0; i < bits_.size(); i++) {
      bits_[i] = 4294967295;
    }
  }
  else {
    for (int i = 0; i < bits_.size(); i++) {
      bits_[i] = 0;
    }
  }
}

BitSet::BitSet(const std::int32_t size) {
  if (size <= 32) {
    size_ = size;
    bits_.push_back(0);
  }
  else {
    std::int32_t prom_size = (size)/ 32;
    for (int i = 0; i < prom_size; i++) {
      bits_.push_back(0);
      size_ = size;
    }
  }
}

bool BitSet::Get(const int32_t idx) const {
  if (idx - 1 > size_ ) {
    throw std::runtime_error("Index out of range");
  }
  else {
    int32_t d = idx - 1;
    int32_t num = d / 32;
    return((bits_[bits_.size() - 1 - num] >> idx) & 1);
  }
}

void BitSet::Set(const int32_t idx, const bool val) {
  int32_t d = idx - 1;
  int32_t num = d / 32;
  if (((bits_[bits_.size() - 1 - num] >> idx) & 1) != val) {
    bits_[bits_.size() - 1 - num] = val;
  }
}