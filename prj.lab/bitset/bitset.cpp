#include <bitset/bitset.hpp>


void BitSet::Fill(const bool val) noexcept {
  if (val) {
    for (int i = 0; i < bits_.size(); i++) {
      bits_[i] = 4294967295;
      size_ += 32;
    }
  }
  else {
    for (int i = 0; i < bits_.size(); i++) {
      bits_[i] = 0;
      size_ = 0;
    }
  }
}

