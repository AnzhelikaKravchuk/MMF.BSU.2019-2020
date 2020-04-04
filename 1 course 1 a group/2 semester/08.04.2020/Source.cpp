#include <io.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();

int main()
{
	char fileName[N] = "List.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int Key = Menu();
		if (Key == Exit)
			return 0;
		system("cls");
		switch (Key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Student);
	//Student* man = new Student;
	Student man;    
	char Ok = 'y';
	while (Ok == 'y')   
	{
		//man->EnterStudent();
		man.EnterStudent();//
		//streamOut.write((char*)man,bufSize);
		streamOut.write((char*)&man, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> Ok;
	}
	//delete man;
	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Student);
	Student man;
	char Ok = 'y';
	while (Ok == 'y')
	{
		man.EnterStudent();
		streamOut.write((char*)&man, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Student);
	Student man;
	long Position;
	InitNumber(Position);
	streamInOut.seekp((Position - 1) * bufSize, ios::beg);
	man.EnterStudent();
	streamInOut.write((char*)&man, bufSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);//*
	long N = streamInOut.tellp();//*
	int bufSize = sizeof(Student);
	Student man;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&man, bufSize))
	{
		//streamInOut.seekp( (Position - 1 + i ) * bufSize, ios::beg);
		//streamInOut.write((char*)&man, bufSize);
		//streamInOut.seekp( bufSize, ios::cur);
		//i++;
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&man, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int DiskriptorFile = open(fileName, 2);//*
	chsize(DiskriptorFile, N - bufSize);//*
	close(DiskriptorFile);//*
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}
		flag = false;
		Student manOne, manTwo;
		int bufSize = sizeof(Student);
		streamInOut.read((char*)&manOne, bufSize);
		while (streamInOut.read((char*)&manTwo, bufSize))
		{
			if (manTwo.GetMiddleMark() < manOne.GetMiddleMark())
			{
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&manTwo, bufSize);
				streamInOut.write((char*)&manOne, bufSize);
				flag = true;
			}
			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&manOne, bufSize);
		}
		streamInOut.close();
	}
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Student);
	Student* man = new Student;
	while (streamIn.read((char*)man, bufSize))
	{
		man->DisplayStudent();
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}