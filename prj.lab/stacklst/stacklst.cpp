#include "Stacklst.hpp"
#include <stdexcept>

bool StackLst::IsEmpty() const noexcept{
	return head_==nullptr;
}

void StackLst::Push(const Complex& val) {
	Node* y = new Node(val, head_);
	head_ = y;
}

Complex& StackLst::Top() {
	if (head_) {
		return head_->v;
	}else{
		throw std::runtime_error("Stack is empty");
	}

}

const Complex& StackLst::Top() const {
	if (head_) {
		return head_->v;
	}
	else {
		throw std::runtime_error("Stack is empty");
	}
}

void StackLst::Pop() noexcept {
	if (head_) {
		Node* t = head_;
		head_ = head_->next;
		delete t;
	}
}