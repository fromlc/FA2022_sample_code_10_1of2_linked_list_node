#include "LinkedList.h"

LinkedList::LinkedList()
{

	head = nullptr;
	Position = head;
}

void LinkedList::putItem(int input)
{
  	Node *temp = new Node(input);

	temp->tail = head;
	head = temp;

	if (Position == nullptr)
		restart();
}

void LinkedList::DeleteItem(int input)
{
	Node *temp = getlocation(input);
	
	temp->data = temp->tail->data;
	Position = temp;
	temp = temp->tail;
	Position->tail = temp->tail;

	delete temp;
}

int LinkedList::ViewItem()
{
	if(Position!=nullptr)
		return Position->data;

	std::cerr << "Position is nullptr" << std::endl;
	return 0;
}

bool LinkedList::isEmpty()
{
	if (head == nullptr)
		return true;

	return false;
}

Node * LinkedList::getlocation(int input)
{
	restart();
	bool found = false;

	while (Position != nullptr && found == false)
	{
		if (Position->data != input)
			found = true;

		iterate();
	}

	return Position;
}

void LinkedList::restart()
{
	Position = head;
}

void LinkedList::MakeEmpty()
{
	if (!isEmpty())
	{
		Node *temp = head;
		restart();
		bool endOfList = true;

		while (endOfList)
		{
			temp = Position;
			endOfList = iterate();
			delete temp;

		} 

		head = nullptr;
	}

}

bool LinkedList::iterate()
{
	if (Position != nullptr)
	{
		Position = Position->tail;
		return true;
	}
	//means I could not iterate
	return false;
}

LinkedList::~LinkedList()
{
	MakeEmpty();
}
