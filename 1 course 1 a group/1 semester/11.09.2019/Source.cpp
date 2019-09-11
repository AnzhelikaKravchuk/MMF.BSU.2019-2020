#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	cout << "Enter the coeff. : \n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	system("cls");

	if (a == 0)
	{
		cout << "Not square equation!" << endl;
		system("pause");
		return 0;
	}

	double d = b * b - 4 * a * c;

	if (d < 0)
	{
		cout << "No real roots!" << endl;
		system("pause");
		return 0;
	}
	else if (d == 0)
	{
		cout << "x1 = x2 = " << -b / 2 / a << endl;
		system("pause");
		return 0;
	}
	else
	{
		cout << "x1 = " << (-b - sqrt(d))/ 2 / a << endl;
		cout << "x2 = " << (-b + sqrt(d)) / 2 / a << endl;
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}