#include <queuearr/queuearr.hpp>
#include <stdexcept>

bool QueueArr::IsEmpty() {
	return !(data_);
}

void QueueArr::Push(const Complex& z) noexcept {
	if (nullptr == data_) {
		capacity_ = 10;
		data_ = new Complex[capacity_];
		tail_ += 1;
	}
	if (tail_ < capacity_) {
		data_[tail_] = z;
		tail_ += 1;
	}
	else {
		capacity_ += 10;
		data_ = new Complex[capacity_];
		data_[tail_] = z;
		tail_ += 1;
	}
}

const Complex& QueueArr::Top() const {
	if (head_) {
		return (data_[head_]);
	}
	else {
		throw std::logic_error("QueueArr is empty.");
	}
}

Complex& QueueArr::Top() {
	if (head_) {
		return (data_[head_]);
	}
	else {
		throw std::logic_error("QueueArr is empty.");
	}
}

void QueueArr::Pop() noexcept {
	if (data_) {
		if (head_ < tail_) {
			head_ += 1;
		}
		else {
			throw std::logic_error("QueueArr is empty.");
		}
	}
	else {
		throw std::logic_error("QueueArr is empty.");
	}
}