#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(char* firstName, char* lastName, char* faculty, int* marks)
{
	this->SetStudent(firstName, lastName, faculty, marks);
}

void Student::SetFirstName(char* firstName)
{
	strcpy(this->firstName, firstName);
}

void Student::SetLastName(char* lastName)
{
	strcpy(this->lastName, lastName);
}

void Student::Setfaculty(char* faculty)
{
	strcpy(this->faculty, faculty);
}

void Student::SetMarks(int* marks)
{
	for (int i = 0; i < M; i++)
	{
		if (marks[i] >= 0 && marks[i] <= 10)
			this->marks[i] = marks[i];
		else
			this->marks[i] = 0;
	}
}

char* Student::GetFirstName()
{
	return this->firstName;
}

char* Student::GetLastName()
{
	return this->lastName;
}

char* Student::Getfaculty()
{
	return this->faculty;
}

double Student::GetMiddleMark()
{
	return this->middleMark;
}

void Student::SetMiddleMark()
{
	this->middleMark = 0;
	for (int i = 0; i < M; i++)
		this->middleMark += this->marks[i];
	this->middleMark /= M;
}

void Student::SetStudent(char* firstName, char* lastName, char* faculty, int* marks)
{
	this->SetFirstName(firstName);
	this->SetLastName(lastName);
	this->Setfaculty(faculty);
	this->SetMarks(marks);
	this->SetMiddleMark();
}

void Student::DisplayStudent()
{
	cout << endl << this->firstName << " " << this->lastName << ", \t";
	cout.precision(3);
	cout << this->middleMark << "  , \t" << this->faculty << ".";
	cout << "\tMarks: ";
	for (int i = 0; i < M; i++)
		cout << this->marks[i] << "  ";
}

void Student::EnterStudent()
{
	const int N = 256;
	char firstName[N] = "", lastName[N] = "", faculty[N] = "";
	cout << "Enter the first name of student:";
	cin.ignore();
	cin.getline(firstName, N, '\n');
	cout << "Enter the last name of student:";
	cin.getline(lastName, N, '\n');
	cout << "Enter the faculty:";
	cin.getline(faculty, N, '\n');
	int* marks = new int[M];
	cout << "Enter the exams:" << endl;
	for (int i = 0; i < M; i++)
	{
		cout << "exam[" << (i + 1) << "] = ";
		cin >> marks[i];
	}
	this->SetStudent(firstName, lastName, faculty, marks);
	delete[] marks;
}