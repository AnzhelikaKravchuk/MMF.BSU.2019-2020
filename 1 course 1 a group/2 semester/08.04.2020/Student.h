#ifndef student_h
#define student_h

const int N = 50;
const int M = 5;

class Student
{
public:
	Student(){}
	Student(char*, char*, char*, int*);
	~Student(){}
	void SetFirstName(char*);
	void SetLastName(char*);
	void Setfaculty(char*);
	void SetMarks(int*);
	void SetStudent(char*, char*, char*, int*);
	double GetMiddleMark();
	char* GetFirstName();
	char* GetLastName();
	char* Getfaculty();
	void EnterStudent();
	void DisplayStudent();
private:
	char firstName[N], lastName[N], faculty[N];
	int marks[M];
	double middleMark;
	void SetMiddleMark();
};

#endif