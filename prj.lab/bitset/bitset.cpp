#include "bitset.hpp"


std::ofstream& BitSet::WriteBinary(std::ofstream& cout)
{
  cout.put('0');
  cout.put(char((size_ >> 24) % 256));
  cout.put(char((size_ >> 16) % 256));
  cout.put(char((size_ >> 8) % 256));
  cout.put(char((size_) % 256));

  char check_sum = 0;
  for (int i = 0; i < bits_.size(); ++i)
  {
    if (i == bits_.size() - 1) {
      cout.put(char((bits_[i]) % 256));
      if (size_ - 32 * i > 8)
        cout.put(char((bits_[i] >> 8) % 256));
      if (size_ - 32 * i > 16)
        cout.put(char((bits_[i] >> 16) % 256));
      if (size_ - 32 * i > 24)
        cout.put(char((bits_[i] >> 24) % 256));
    }
    else {
      int a = (bits_[i]) % 256;
      int b = (bits_[i] >> 8) % 256;
      int c = (bits_[i] >> 16) % 256;
      int d = (bits_[i] >> 24) % 256;

      cout.put(a);
      cout.put(b);
      cout.put(c);
      cout.put(d);
    }

    bool check_flag = false;
    for (int j = 0; j < 32; ++j) if ((bits_[i] >> j) % 2 == 1)
      check_flag = !check_flag;

    check_sum = (check_sum | ((check_flag ? 1 : 0) << (7 - (i % 8))));

    if (i % 8 == 7 || i == bits_.size() - 1)
      cout.put(check_sum);
  }

  cout.put(char(255));
  return cout;
}

std::ifstream& BitSet::ReadBinary(std::ifstream& cin)
{
  if (std::cin.good())
  {
    if (cin.get() != '0')
      cin.setstate(std::ios_base::failbit);
    else
    {
      //init size_
      {
        char a = cin.get();
        char b = cin.get();
        char c = cin.get();
        char d = cin.get();
        size_ = (a << 24) | (b << 16) | (c << 8) | d;
      }
      bits_.resize(size_ / 32 + (size_ %32 > 0));

      char check_sum = 0;
      for (int i = 0; i < bits_.size() && cin.good(); ++i)
      {
        if (i == bits_.size() - 1) {
          unsigned char a = 0;
          unsigned char b = 0;
          unsigned char c = 0;
          unsigned char d = 0;

          a = cin.get();
          if (size_ - 32 * i > 8)
            b = cin.get();
          if (size_ - 32 * i > 16)
            c = cin.get();
          if (size_ - 32 * i > 24)
            d = cin.get();

          bits_[i] = a | (b << 8) | (c << 16) | (d << 24);
        }
        else {
          unsigned char a = cin.get();
          unsigned char b = cin.get();
          unsigned char c = cin.get();
          unsigned char d = cin.get();
          int a_i = (int(a) % (1 << 8));
          int b_i = ((int(b) << 8) % (1 << 16));
          int c_i = ((int(c) << 16) % (1 << 24));
          int d_i = ((int(d) << 24));
          bits_[i] = a_i | b_i | c_i | d_i;
        }

        bool check_flag = false;
        for (int j = 0; j < 32; ++j) if ((bits_[i] >> j) % 2 == 1)
          check_flag = !check_flag;

        check_sum = (check_sum | ((check_flag ? 1 : 0) << (7 - (i % 8))));

        if (i % 8 == 7 || i == bits_.size() - 1)
          if (cin.get() != check_sum)
            cin.setstate(std::ios_base::failbit);
      }

      if (cin.good() && cin.get() != 255)
        cin.setstate(std::ios_base::failbit);
    }
  }
  return cin;
}



BitSet::BitSet(const BitSet& other)
    : size_{other.size_},
      bits_{other.bits_}{}
BitSet::BitSet(BitSet&& other) noexcept
    : size_{other.size_},
      bits_{std::move(other.bits_)} {
        other.size_ = 0;
}
BitSet::BitSet(const int32_t size)
    : size_{size},
      bits_{static_cast<uint32_t>((size % 32) == 0 ? (size / 32) : ((size / 32) + 1))}{}

BitSet& BitSet::operator=(const BitSet& other) {
    size_ = other.size_;
    bits_ = other.bits_;
    return *this;  
}
BitSet& BitSet::operator=(BitSet&& other) noexcept {
    size_ = other.size_;
    bits_ = std::move(other.bits_);
    other.size_ = 0;
    return *this;
}

bool BitSet::operator==(const BitSet& rhs) const noexcept {
    if (Size() == rhs.Size()) {
        for (int32_t i_bit{}; i_bit < Size(); i_bit++) {
            if (Get(i_bit) != rhs.Get(i_bit)) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
    // TODO: Как сравнивать два разных по длине битсета?
}
bool BitSet::operator!=(const BitSet& rhs) const noexcept {
    return !(*this == rhs);
}

void BitSet::Resize(const int32_t size) {
    size_ = size;
    int32_t new_bits_vector_size = (size % 32) == 0 ? (size / 32) : ((size / 32) + 1);
    bits_.resize(new_bits_vector_size, 0);
}
bool BitSet::Get(const int32_t idx) const {
    if (Size() < (idx + 1)) {
        throw std::logic_error("BitSet have zero size");
    }
    int32_t bits_el_idx = idx / 32;
    int32_t el_bit_idx = idx % 8;
    return bits_[bits_el_idx] & (1 << el_bit_idx);
}
void BitSet::Set(const int32_t idx, const bool val) {

    int32_t bits_el_idx = idx / 32;
    int32_t el_bit_idx = idx % 8;
    if (val) {
        bits_[bits_el_idx] |= (1 << el_bit_idx);
    }
    if (!val) {
        bits_[bits_el_idx] &= ~(1 << el_bit_idx);
    }
}
void BitSet::Fill(const bool val) noexcept {
    for(auto el{bits_.begin()}; el != bits_.end(); el++) {
        *el = val ? UINT32_MAX : 0;
    }
    // TODO: Нужно ли оставлять значения после size_ по умолчанию(вроде 0)?
}

BitSet& BitSet::operator&=(const BitSet& rhs) {
    // bits_[i] & rhs.bits_[i]
    if (Size() != rhs.Size()) {
        throw std::logic_error("BitSet's have different sizes");
    }
    for (int32_t i_el; i_el <= bits_.size(); i_el++) {
        bits_[i_el] &= rhs.bits_[i_el]; 
    }
    return *this;

}
BitSet& BitSet::operator|=(const BitSet& rhs) {
    if (Size() != rhs.Size()) {
        throw std::logic_error("BitSet's have different sizes");
    }
    for (int32_t i_el; i_el <= bits_.size(); i_el++) {
        bits_[i_el] |= rhs.bits_[i_el]; 
    }
    return *this;
}
BitSet& BitSet::operator^=(const BitSet& rhs) {
    if (Size() != rhs.Size()) {
        throw std::logic_error("BitSet's have different sizes");
    }
    for (int32_t i_el; i_el <= bits_.size(); i_el++) {
        bits_[i_el] ^= rhs.bits_[i_el]; 
    }
    return *this;
}
BitSet BitSet::operator~() {
    BitSet temp_bitset(*this);
    for (int32_t i_el; i_el <= temp_bitset.bits_.size(); i_el++) {
        temp_bitset.bits_[i_el] = ~(temp_bitset.bits_[i_el]);
    }
    return temp_bitset;
}

BitSet::BiA BitSet::operator[](const int32_t idx) {
  return BiA(*this, idx);
}


BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
    if (lhs.Size() != rhs.Size()) {
        throw std::logic_error("BitSet's have different sizes");
    }
    BitSet temp_lhs(lhs);
    return temp_lhs &= rhs;
}
BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
    if (lhs.Size() != rhs.Size()) {
        throw std::logic_error("BitSet's have different sizes");
    }
    BitSet temp_lhs(lhs);
    return temp_lhs |= rhs;
}
BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
    if (lhs.Size() != rhs.Size()) {
        throw std::logic_error("BitSet's have different sizes");
    }
    BitSet temp_lhs(lhs);
    return temp_lhs ^= rhs;
}
