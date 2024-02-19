class QueueLst{
public:
	QueueLst() = default;

	QueueLst(const QueueLst&) = default;
	~QueueLst() = default;
private:
  struct Node {
    Node(Complex v_, Node* n) { v = v_; next = n; }
    Complex v;
    Node* next = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
}
