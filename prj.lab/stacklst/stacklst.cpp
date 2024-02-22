#include "Stacklst.hpp"
#include <stdexcept>


StackLst::StackLst(const StackLst& a) {
	Node* src = a.head_;
	Node* dest = nullptr;
	Node* new_node = nullptr;

	while (src != nullptr) {
		new_node = new Node(src->v, nullptr);

		if (head_ == nullptr) {
			head_ = new_node;
			dest = head_;
		}
		else {
			dest->next = new_node;
			dest = dest->next;
		}

		src = src->next;
	}
}


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

void StackLst::Clear() noexcept{
	while (head_) {
		Node* t = head_;
		head_ = head_->next;
		delete t;
	}
}