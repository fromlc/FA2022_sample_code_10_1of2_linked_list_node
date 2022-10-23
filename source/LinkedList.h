#pragma once
#include <iostream>
class Node
{
public:
	int data;
	Node * tail;

	Node()
	{
		tail = nullptr;
	}

	Node(int input)
	{
		Node();
		data = input;
	}
};

class LinkedList
{
	Node *head;
	Node *Position;

public:
	LinkedList();
	void putItem(int);//place new node at begining of list
	void DeleteItem(int);
	int ViewItem();//return current position item
	bool isEmpty();
	Node * getlocation(int);
	void restart();
	void insert(int);
	void iterate();
	~LinkedList();
};

