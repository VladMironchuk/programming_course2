#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() 
{
	cout<<"enter the surname of the student: ";
	cin >> studentSurname;
	cout << "enter the name of the student: ";
	cin >> studentName;
	cout << "enter the patronymic of the student: ";
	cin >> studentPatronymic;
	cout << "enter the birthday of the student(YYYY.DD.MM) : ";
	cin >> studentBirthday;
	cout << "enter the adress of the student: ";
	cin >> studentAdress;
	cout << "enter the phone of the student: ";
	cin >> studentPhone;
	cout << "enter the faculty of the student: ";
	cin >> studentFac;
	cout << "enter the course of the student: ";
	cin >> studentCourse;
	cout << endl;
}

char* Student::getStudentSurname()
{
	return studentSurname;
}


char* Student::getStudentName()
{
	return studentName;
}

char* Student::getStudentPatronymic()
{
	return studentPatronymic;
}

char* Student::getStudentBirthday()
{
	return studentBirthday;
}

char* Student::getStudentAdress()
{
	return studentAdress;
}

char* Student::getStudentPhone()
{
	return studentPhone;
}

char* Student::getStudentFac()
{
	return studentFac;
}

int Student::getStudentCourse()
{
	return studentCourse;
}

void Student :: facultyList(Student list[], int n)
{
	char fac[30];
	cout << "\nchoose a faculty : ";
	cin >> fac;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(list[i].getStudentFac(), fac) == 0)
			list[i].showStudent();
	}
}

void Student :: studentFacList(Student list[], int n)
{
	char fac[30];
	int* fac1 = new int[n];
	for (int i = 0; i < n; i++)
		fac1[i] = 1;
	for (int i = 0; i < n; i++)
	{
		strcpy_s(fac, list[i].getStudentFac());
		if (fac1[i])
			cout << fac << " : " << endl;
		for (int k = i; k < n; k++)
		{
			if ((strcmp(list[k].getStudentFac(), fac) == 0) && fac1[k]) {
				fac1[k] = 0;
				list[k].showStudent();
			}
		}
	}
}

void Student :: studentCourseList(Student list[], int n)
{
	int course;
	int* fac1 = new int[n];
	for (int i = 0; i < n; i++)
		fac1[i] = 1;
	for (int i = 0; i < n; i++)
	{
		course = list[i].getStudentCourse();
		if (fac1[i])
			cout << course << " course :" << endl;
		for (int k = i; k < n; k++)
		{
			if (course == list[k].getStudentCourse() && fac1[k]) {
				fac1[k] = 0;
				list[k].showStudent();
			}
		}
	}
}

void Student :: studentBirthYear(Student list[], int n)
{
	char year1[5], year[5];
	cout << "enter a year : " << endl;
	cin >> year;
	for (int i = 0; i < n; i++)
	{
		strncpy_s(year1, list[i].getStudentBirthday(), 4);
		if (year < year1)
			list[i].showStudent();
	}

}

void Student::showStudent()
{
	cout << "Surname : " << studentSurname << "\nName : " << studentName << "\nPatronymic : " << studentPatronymic << "\nBirthday : " << studentBirthday
		<< "\nAdress : " << studentAdress << "\nPhone : " << studentPhone << "\nFaculty : " << studentFac << "\nCourse : " << studentCourse << endl << endl;
}


Student::~Student()
{
	cout << "destructed\n";
}