#include <iostream>

using namespace std;

short enterDigit();//прототип функции!
int enterNumber();//прототип функции!
void displayResult(int, short, int);//прототип функции!
int countDigitInNumber(int, short);//прототип функции!

int main()
{
	int number = enterNumber();
	
	short digit = enterDigit();
	
	int count = countDigitInNumber(number, digit);
	
	displayResult(number, digit, count);

	system("pause");
	
	return 0;
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
