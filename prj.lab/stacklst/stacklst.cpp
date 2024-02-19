#include "Stacklst.hpp"
#include <stdexcept>


StackLst::StackLst(const StackLst& w) {
	if (w.head_) {
		Node* current = w.head_;
		head_ = new Node(current->v, nullptr); // Создаем новый узел с данными из первого узла во входном стеке
		Node* newCurrent = head_;
		Node* oldCurrent = current;
		int size_w = 1; // Учитываем первый узел

		while (oldCurrent->next) {
			oldCurrent = oldCurrent->next;
			newCurrent->next = new Node(oldCurrent->v, nullptr); // Создаем новый узел для каждого узла во входном стеке
			newCurrent = newCurrent->next;
			size_w++;
		}

		Node* current = head_;
		head_ = new Node(current->v, nullptr); // Создаем новый узел с данными из первого узла во входном стеке
		Node* newCurrent = head_;
		Node* oldCurrent = current;
		int size_ = 1; // Учитываем первый узел

		while (oldCurrent->next) {
			oldCurrent = oldCurrent->next;
			newCurrent->next = new Node(oldCurrent->v, nullptr); // Создаем новый узел для каждого узла во входном стеке
			newCurrent = newCurrent->next;
			size_++;
		}
		
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

void StackLst::Clear() {
	while (head_) {
		Node* t = head_;
		head_ = head_->next;
		delete t;
	}
}