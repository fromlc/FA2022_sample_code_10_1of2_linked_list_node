//------------------------------------------------------------------------------
// Node class declaration and definition
//------------------------------------------------------------------------------
#ifndef NODE_H
#define NODE_H

//------------------------------------------------------------------------------
// Each Node class instance is a linked list node 
//------------------------------------------------------------------------------
class Node {
private:
public:
	int   data;
	Node* next;

	// constructors
	Node() : Node(0) {}

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

// Or a linked list node can be a struct
struct s_Node {
	int   data;
	struct s_Node* next;

	// constructors
	s_Node() : s_Node(0) {}

	s_Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};
#endif	// NODE_H
