#pragma once
#include<iostream>

using namespace std;

class IntegerWrapper
{
public:
	IntegerWrapper()
	{
		//?IntegerWrapper(0);
		cout << "Ctor works!" << endl;
		pointer = new int(0);
	}
	
	IntegerWrapper(int value)
	{
		cout << "Ctor works!" << endl;
		pointer = new int(value);
	}

	/*IntegerWrapper(const IntegerWrapper& other)
	{
		cout << "Copy ctor works!" << endl;
		this->pointer = new int(*other.pointer);
	}*/
	
	//this->pointer = other -> pointer; // bad code

	~IntegerWrapper()
	{
		cout << "Dtor works!" << endl;
		delete pointer;
	}

	IntegerWrapper&  operator = (const IntegerWrapper& other)
	{
		cout << "operator = works!" << endl;

		if (&other == this)
		{
			return *this;
		}

		this->pointer = new int(*other.pointer);
		return *this;
	}
	
	friend ostream& operator << (ostream& stream, IntegerWrapper& wrapper)
	{
		stream << *wrapper.pointer;
		return stream;
	}
	
	friend istream& operator >> (istream& stream, IntegerWrapper& wrapper)
	{
		stream >> *wrapper.pointer;
		return stream;
	}
private:
	int* pointer = nullptr;
};