#include <iostream> 
#include "MenuFunctions.h"

using namespace std;

short enterDigit();//прототип функции!
int enterNumber();//прототип функции!
void displayResult(int, short, int);//прототип функции!
void count(int, short&, short&, short&);//прототип функции!
void countTests(int, int, short, short, short);
void menu();
void workWithConsole();
void runTests();

int main()
{
	menu();
	return 0;
}

void workWithConsole()
{
	int number = enterNumber();

	short digit = enterDigit();

	int count = 0;// countDigitInNumber(number, digit);

	displayResult(number, digit, count);
}

void runTests()
{
	int testNumber = 1;

	countTests(testNumber++, -657444, 2, 2, 1);
	countTests(testNumber++, 222222, 5, 0, 0);

}


void menu()
{
	while (true)
	{
		char operation;
		menuText();
		cin >> operation;
		switch (operation)
		{
		case '1':
			workWithConsole();
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

short enterDigit()
{
	short digit;

	while (true)
	{
		cout << "Enter digit (0..9): ";
		cin >> digit;

		if (digit >= 0 && digit <= 9)
		{
			break;
		}

		cout << "Not digit! Try again." << endl;
		system("pause");
		system("cls");
	}

	return digit;
}

int enterNumber()
{
	int number;

	cout << "Enter number: ";
	cin >> number;

	return number;
}

void displayResult(int number, short digit, int count)
{
	cout << "There are " << count << " digit '" << digit
		<< "' in " << number << "." << endl;
}

void count(int number, short& s1, short& s2, short& s3)
{

}

void countTests(int testCaseNumber, int number, 
	short expected1, short expected2, short expected3)
{
	short actual1 = 0, actual2 = 0, actual3 = 0;
	count(number, actual1, actual2, actual3);
	 
	if (actual1 == expected1 && actual2 == expected2 && actual3 == expected3)
	{
		cout << "Case #" << testCaseNumber << " is correct. :)" << endl;
	}
	else
	{
		cout << "Case #" << testCaseNumber << " IS NOT CORRECT. :(" << endl;
		//cout << "\t actual = " << actual << ", but expected = " << expectedCount << endl;
	}
}