#include "bitset.hpp"



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

BitSet::BiA& BitSet::operator[](const int32_t idx) {
    // return BiA(*this, idx);
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
