#pragma once

#include <iostream>

using namespace std;

namespace ArrayExtension
{
#pragma region declarations of functions
	void swap(int&, int&);
	void swap(int *, int *);
	int* allocateMemory(int);
	void initializationArray(int * const, int);
	void freeMemory(int * const);
	void displayArray(int const *, int);
	void removeElement(int * const, int&, int);
	void bubleSort(int*, int);
	bool areEqual(int* lhs, int n, int* rhs, int m);
	void dataValidation(int* array, int n);
	int* generateSortedArray(int, int, int);
	void shuffleArray(int*, int);
#pragma endregion

#pragma region definitions of functions

	void shuffleArray(int * array, int size)
	{
		//TODO
	}

	int* generateSortedArray(int size, int start, int step)
	{
		if (size <= 0)
		{
			throw std::out_of_range("Dimension of array must be more zero!");
		}

		int* array = new int[size];

		for (int* p = array, i = start; p < array + size; p++)
		{
			*p = start;
			start += step;
		}

		return array;
	}
	
	void initializationArray(int * const array, int size)
	{
		dataValidation(array, size);

		for (int* p = array; p < array + size; p++)
		{
			*p = rand() % 100;
		}
	}

	int* allocateMemory(int size)
	{
		if (size <= 0)
		{
			throw std::out_of_range("Dimension of array must be more zero!");
		}

		int* array = new int[size];// std::bad_alloc();

		return array;
	}

	void freeMemory(int * const array)
	{
		if (array == nullptr)
		{
			throw std::invalid_argument("Argument is null!");
		}

		delete[] array;
	}

	void displayArray(const int * array, int size)
	{
		

		for (const int* p = array; p < array + size; p++)
		{
			std::cout << *p << " ";
		}
	}

	void removeElement(int * const array, int& n, int k)
	{
		if (n <= 0)
		{
			throw std::out_of_range("Dimension of array must be more zero!");
		}

		if (k < 0 || k > n)
		{
			throw std::out_of_range("Position  of array must be more than  zero and less then!");
		}

		if (array == nullptr)
		{
			throw std::invalid_argument("Argument is null!");
		}

		for (int i = k; i < n - 1; i++)
		{
			array[i] = array[i + 1];
		}

		n--;
	}

	void bubleSort(int* array, int size)
	{
		dataValidation(array, size);

		bool isSorted = false;

		int i = 0;

		while (!isSorted)
		{
			isSorted = true;
			for (int j = size - 1; j > i; j--)
			{
				if (array[j] < array[j - 1])
				{
					swap(array[j], array[j - 1]);
					isSorted = false;
				}
			}
			i++;
		}
	}

	void dataValidation(int* array, int size)
	{
		if (size <= 0)
		{
			throw std::out_of_range("Dimension of array must be more zero!");
		}

		if (array == nullptr)
		{
			throw std::invalid_argument("Argument is null!");
		}
	}

	bool areEqual(int* lhs, int n, int* rhs, int m)
	{
		dataValidation(lhs, n);

		dataValidation(rhs, m);

		if (n != m)
		{
			return false;
		}

		for (int* p = lhs, *q = rhs; p < lhs + n; p++, q++)
		{
			if (*p != *q)
			{
				return false;
			}
		}

		return true;
	}

	void swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = t;
	}

	void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}

#pragma endregion
}