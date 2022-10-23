//------------------------------------------------------------------------------
// CS 281-0798, Fall 2022
//
// Week 10 Example Code #1
// Signature linked list data types
//
// A linked list node, or data item plus pointer, can be 
//      1) a named structure or
//      2) a class.
//
// When you see a data structure that includes a pointer 
// to itself, you're seeing the signature of a linked list.
// 
// NOTE: this code does not release memory - 
// all memory is released when the app terminates
//------------------------------------------------------------------------------
#include <iostream>

#include "Node.h"

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
//#define STACK	// comment this line to insert at tail (QUEUE)

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::string;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
Node* g_pHead = nullptr;
Node* g_pTail = nullptr;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void insertAtHead(Node* pNew);
void insertAtTail(Node* pNew);
void displayNode(const string& s, Node* p);

//------------------------------------------------------------------------------
// entry point 
//------------------------------------------------------------------------------
int main() {
#ifdef STACK
	cout << "STACK implemented as a linked list\n\n";
#else
	cout << "QUEUE implemented as a linked list\n\n";
#endif

	// Class instance nodes: pcN is working pointer
	Node* pcN = new Node(5);
	displayNode("first node", pcN);

	// Save pointers to our first item as the head and tail
	g_pHead = pcN;
	g_pTail = pcN;

	// Create a second node
	pcN = new Node(10);
	displayNode("second node", pcN);

#ifdef STACK
	// Insert second node into list and make it the list head
	insertAtHead(pcN);
#else
	// Insert second node into list and make it the list tail
	insertAtTail(pcN);
#endif

	// Second node after insertion
	displayNode("second node after insertion", pcN);

	// Create a third node
	pcN = new Node(15);
	displayNode("third node", pcN);

#ifdef STACK
	// Insert third node into list and make it the list head
	insertAtHead(pcN);
#else
	// Insert third node into list and make it the list tail
	insertAtTail(pcN);
#endif

	// Third node after insertion
	displayNode("third node after insertion", pcN);

	// Traverse the list
	cout << "Traverse the list starting with the list head\n\n";
	
	// Save the pointer to the list head!
	pcN = g_pHead;
	while (pcN != nullptr) {
		displayNode("next node", pcN);
		pcN = pcN->next;
	}

	cout << "Type any key to continue\n";
	cin.get();

	// Using struct nodes
	cout << "Syntax for using struct nodes\n\n";
	struct s_Node* p_sN = new s_Node;
	cout << "(struct) p_sN.data: " << p_sN->data << '\n';
	cout << "(struct) p_sN.next: " << p_sN->next << '\n';

	cout << "\nType any key to continue\n";
	cin.get();

	return 0;
}

//------------------------------------------------------------------------------
// insert node pointed to by pNew as the new list head (create STACK)
//------------------------------------------------------------------------------
void insertAtHead(Node* pNew) {
	pNew->next = g_pHead;
	g_pHead = pNew;
}

//------------------------------------------------------------------------------
// insert node pointed to by pNew as the new list tail (create QUEUE)
//------------------------------------------------------------------------------
void insertAtTail(Node* pNew) {
	g_pTail->next = pNew;
	g_pTail = pNew;
}

//------------------------------------------------------------------------------
// display node pcN's data and its next pointer
//------------------------------------------------------------------------------
void displayNode(const string& s, Node* pcN) {
	cout << "(" << s << ") pcN: " << pcN << '\n';
	cout << "(" << s << ") pcN->data: " << pcN->data << '\n';
	cout << "(" << s << ") pcN->next: " << pcN->next << "\n\n";
}
