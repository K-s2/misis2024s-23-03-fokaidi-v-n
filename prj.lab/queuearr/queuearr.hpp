#pragma once
#ifndef QUEUELST_QUEUELST_HPP_20240220
#define QUEUELST_QUEUELST_HPP_20240220

#include <complex/complex.hpp>

#include <cstddef>

class QueueArr {

public:
	QueueArr() = default;

	QueueArr(const QueueArr&) = default;

	bool IsEmpty();

	void Pop() noexcept;

	void Push(const Complex& z) noexcept;

	[[nodiscard]] Complex& Top();

	[[nodiscard]] const Complex& Top() const;

	void Clear() noexcept;

private:
	std::ptrdiff_t capacity_ = 10;
	Complex* data_ = nullptr;
	std::ptrdiff_t tail_ = 0;
	std::ptrdiff_t head_ = 0;
};


#endif