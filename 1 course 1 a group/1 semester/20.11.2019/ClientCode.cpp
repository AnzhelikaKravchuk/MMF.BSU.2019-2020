#include "ArrayExtension.h"

using namespace ArrayExtension;

void runTests();
void testCase(int*, int, int*, int);
void menu();

int main()
{
	int n = 15;
	int * array = generateSortedArray(n, -23, 4);
	cout << endl;
	displayArray(array, n);
	ArrayExtension::shuffleArray(array, n);
	cout << endl;
	displayArray(array, n);
	ArrayExtension::bubleSort(array, n);
	cout << endl;
	displayArray(array, n);
	cout << endl;
	runTests();
}

void menu()
{
	while (true)
	{
		char operation;
		//menuText();
		cin >> operation;
		switch (operation)
		{
		case '1':
			//workWithConsole();
			break;
		case '2':
			runTests();
			break;
		case '3':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}
		system("pause");
		system("cls");
	}
}


void testCase(int* expected, int n, int* actual, int m)
{
	bubleSort(actual, m);

	if (areEqual(expected, n, actual, m))
	{
		cout << " True " << endl;
	}
	else
	{
		cout << " False " << endl;
	}
}

void runTests()
{
	int testNumber = 1;

	int n = 5;

	int* expected = new int[n] { 1, 2, 3, 4, 5 };
	int* actual = new int[n] {5, 4, 3, 2, 1};
	testCase(expected, n, actual, n);
	freeMemory(expected);
	freeMemory(actual);

	n = 10;
	expected = new int[n] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	actual = new int[n] {5, 4, 3, 2, 1, 8, 7, 10, 6, 9};
	testCase(expected, n, actual, n);
	freeMemory(expected);
	freeMemory(actual);

	n = 10;
	expected = new int[n] { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	actual = new int[n] {3, 3, 1, 1, 2, 2, 5, 5, 4, 4};
	testCase(expected, n, actual, n);
	freeMemory(expected);
	freeMemory(actual);

	n = 100000;
	expected = generateSortedArray(n, -89, 3);
	actual = generateSortedArray(n, -89, 3);
	shuffleArray(actual, n);
	testCase(expected, n, actual, n);
	freeMemory(expected);
	freeMemory(actual);
}