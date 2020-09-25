#include <iostream>
#include "Student.h"
using namespace std;


int main()
{
	int n, k = 1;
	Student* student;
	cout << "enter a number of students : ";
	cin >> n;
	cout << endl;
	student = new Student[n];
	while (k)
	{
		cout << "choose an operation :" << endl
			<< "1 - list of students of a given faculty" << endl
			<< "2 - lists of students for each faculty and course" << endl
			<< "3 - list of students born after a given year" << endl
			<< "0 - exit" << endl;
		cout << "operation : "; cin >> k;
		switch (k)
		{
		case 1 :
			student->facultyList(student, n);
			break;
		case 2:
			student->studentFacList(student, n);
			student->studentCourseList(student, n);
			break;
		case 3:
			student->studentBirthYear(student, n);
			break;
		}
	}
	delete[] student;
	return 0;
}