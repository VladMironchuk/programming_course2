#include "Employer.h"
#include <iostream>
using namespace std;

void Manager::showJob() {
	cout << "Job is Manager" << endl;
}

void Manager::moneyPerLife() {
	double M = 1000 * 12 * wage;
	cout <<"Salary of Manager is 1000"<<endl <<"All owned money is " << M << endl;
}

void Admin::showJob() {
	cout << "Job is Admin" << endl;
}

void Admin::moneyPerLife() {
	double M = 2000 * 12 * wage;
	cout<<"Salary of Manager is 2000" << endl << "All owned money is " << M << endl;
}

void Programmer::showJob() {
	cout << "Job is Programmer" << endl;
}

void Programmer::moneyPerLife() {
	double M = 5000 * 12 * wage;
	cout<<"Salary of Manager is 5000" << endl  << "All owned money is " << M << endl;
}
