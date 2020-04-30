#include <iostream>

#include "LinkedList.h"

int main()
{
	LinkedList linkedList;
	linkedList.addFirst(1);
	linkedList.addFirst(2);
	linkedList.addFirst(3);
	cout << linkedList;

	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	LinkedList linkedList1(array, 10);
	cout << linkedList1;
	linkedList1.addAfterItem(8, 12);
	linkedList1.addBeforeItem(1, 12);
	linkedList1.addLast(111);
	cout << linkedList1;
	linkedList1.clear();
	cout << linkedList1;
}