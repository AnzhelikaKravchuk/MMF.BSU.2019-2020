#include<iostream>

using namespace std;

void swap(int&, int&);
int inputDimension(int);
void swap(int*, int*);
void inputArray(int*, int);
void randomArray(int*, int, int);
void generatorArray(int*, int, int, int);
void displayArray(int*, int);

int main()
{
	return 0;
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void inputArray(int* array, int n)
{
	if (array == nullptr)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	if (n <= 0)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	for (int* p = array, i = 0; p < array + n; p++, i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> *p;
	}
}

void displayArray(int* array, int n)
{
	if (array == nullptr)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	if (n <= 0)
	{
		cout << "Invalid data!" << endl;
		return;
	}


	for (int* p = array; p < array + n; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

}

void randomArray(int * array, int n, int max)
{
	if (array == nullptr)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	if (n <= 0)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % max - max / 2;//<- 0..max
	}
}

void generatorArray(int* array, int n, int start, int step)
{
	if (array == nullptr)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	if (n <= 0)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		array[i] = start;
		start += step;
	}
}

int inputDimension(int dimension)
{

	int n;

	while (true)
	{
		cout << "Enter dimension of array <= " << dimension << " :";
		cin >> n;
		if (n >= 1 && n <= dimension)
		{
			break;
		}

		cout << "Invalid data!";
	}

	return n;
}






