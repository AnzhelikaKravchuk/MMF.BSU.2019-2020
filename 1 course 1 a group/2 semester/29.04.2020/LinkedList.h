#pragma once
#include <ostream>

using namespace std;

class LinkedList
{
public:
	LinkedList();
	LinkedList(int*, int);
	~LinkedList();
	bool isEmpty();
	void addFirst(int);
	void addLast(int);
	void addBeforeItem(int, int);
	void addAfterItem(int, int);
	void clear();
	friend std::ostream& operator << (ostream& stream, const LinkedList& node);
private:
	struct Node
	{
		Node() : next(nullptr){ }
		Node(int value) : item(value), next(nullptr) { }
		friend std::ostream& operator << (ostream& stream, const Node& node)
		{
			stream << node.item << " -> ";
			return stream;
		}
		int item{ 0 };
		Node* next;//Node* previous;
	};
	
	Node* head;//Node* tail;
};