#include <iostream> 
#include "MenuFunctions.h"

using namespace std;

short enterDigit();//прототип функции!
int enterNumber();//прототип функции!
void displayResult(int, short, int);//прототип функции!
int countDigitInNumber(int, short);//прототип функции!
void countDigitInNumberTests(int, int, short, int);
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

	int count = countDigitInNumber(number, digit);

	displayResult(number, digit, count);
}

void runTests()
{
	int testNumber = 1;

	countDigitInNumberTests(testNumber++, -657444, 
		4, 3);
	countDigitInNumberTests(testNumber++, -100000, 
		0, 5);
	countDigitInNumberTests(testNumber++, 1222442, 
		2, 4);
	countDigitInNumberTests(testNumber++, -1, 
		0, 0);
	countDigitInNumberTests(testNumber++, 0,
		0, 1);
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

int countDigitInNumber(int number, short digit)
{
	number = abs(number);

	int count = 0;

	while (number)
	{
		short rest = number % 10;

		if (rest == digit)
		{
			count++;
		}

		number /= 10;
	}

	return count;
}

void countDigitInNumberTests(int testCaseNumber, int number, short digit, int expectedCount)
{
	int actual = countDigitInNumber(number, digit);
	if ( actual == expectedCount)
	{
		cout << "Case #" << testCaseNumber << " is correct. :)" << endl;
	}
	else
	{
		cout << "Case #" << testCaseNumber << " IS NOT CORRECT. :(" << endl;
		cout << "\t actual = " << actual << ", but expected = " << expectedCount << endl;
	}
}
