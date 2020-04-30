#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList() : head(nullptr)
{
}

LinkedList::LinkedList(int* values, int n) : head(nullptr)
{
	//TODO validation

	for (int i = n - 1; i >= 0; i--)
	{
		addFirst(values[i]);
	}
}

LinkedList::~LinkedList()
{
	clear();
	cout << *this;
}

bool LinkedList::isEmpty()
{
	return !head;
}

void LinkedList::addFirst(int value)
{
	Node* node = new Node(value);

	if (isEmpty())
	{
		head = node;
		return;
	}

	node->next = head;
	head = node;
}

void LinkedList::addLast(int value)
{
	Node* current = head, *previous = current;

	while (current)
	{
		previous = current;
		current = current->next;
	}

	Node* node = new Node(value);
	
	previous->next = node;
}

void LinkedList::addBeforeItem(int tag, int value)
{
	if (isEmpty())
	{
		return;
	}

	Node* current = head,
		* previous = current;

	while (current)
	{
		if (current->item == tag)
		{
			if (current == head)
			{
				addFirst(value);
			}
			else
			{
				Node* node = new Node(value);
				previous->next = node;
				node->next = current;
			}
			return;
		}

		previous = current;
		current = current->next;
	}
}

void LinkedList::addAfterItem(int tag, int value)
{
	if (isEmpty())
	{
		return;
	}

	Node* current = head;

	while (current)
	{
		if (current->item == tag)
		{
			Node* node = new Node(value);
			node->next = current->next;
			current->next = node;
			return;
		}

		current = current->next;
	}
}

void LinkedList::clear()
{
	Node* current = head;
	while (current)
	{
		head = current->next;
		delete current;
		current = head;
	}
}

std::ostream& operator<<(ostream& stream, const LinkedList& list)
{
	LinkedList::Node* current = list.head;
	
	if (current == nullptr)
	{
		stream << "List is empty." << endl;
		return stream;
	}

	while (current)
	{
		stream << *current;
		current = current->next;
	}

	stream << endl;
	
	return stream;
}