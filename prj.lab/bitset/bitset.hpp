// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef BITSET_BITSET_HPP_20240318
#define BITSET_BITSET_HPP_20240318

#include <cstdint>
#include <iosfwd>
#include <vector>
#include <stdexcept>

class BitSet {
public:
  class BiA {
    public:
      BiA() = delete;
      BiA(BitSet& bs, const int32_t idx);
      BitSet& operator=(const BiA&);
      BitSet& operator=(bool val);
      operator bool() const;
    private:
      BitSet& bs_;
      int32_t idx;
  };

  BitSet() = default;

  BitSet(const BitSet&);

  BitSet(BitSet&&) noexcept;

  BitSet(const int32_t);

  BitSet& operator=(const BitSet&);

  BitSet& operator=(BitSet&&) noexcept;

  ~BitSet() = default;

  [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;

  [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

  int32_t Size() const noexcept { return size_; }

  void Resize(const int32_t size); // 0 < size

  [[nodiscard]] bool Get(const int32_t idx) const;

  void Set(const int32_t idx, const bool val);

  void Fill(const bool val) noexcept;

  [[nodiscard]] BitSet& operator&=(const BitSet& rhs);

  [[nodiscard]] BitSet& operator|=(const BitSet& rhs);

  [[nodiscard]] BitSet& operator^=(const BitSet& rhs);

  [[nodiscard]] BitSet operator~();

  BiA& operator[](const int32_t);
  // std::ostream& WriteTxt(std::ostream&)
  // std::ostream& WriteBinary(std::ostream&)
  // std::istream& ReadTxt(std::istream&)
  // std::istream& RaadBinary(std::istream&)
private:
  std::int32_t size_ = 0;
  std::vector<uint32_t> bits_;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif
