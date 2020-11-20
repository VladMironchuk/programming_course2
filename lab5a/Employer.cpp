#include <iostream>
#include "Employer.h"
#include <string.h>

using namespace std;

void Manager::showJob() {
	cout << "Manager" << endl;
}

void Admin::showJob() {
	cout << "Admin" << endl;
}

void Programmer::showJob() {
	cout << "Programmer" << endl;
}

void Manager::showMoneyPerWorking()
{
	cout << this->salary * this->wage * 12 << endl;
}

void Admin::showMoneyPerWorking()
{
	cout << this->salary * this->wage * 12 << endl;
}

void Programmer::showMoneyPerWorking()
{
	cout << this->salary * this->wage * 12 << endl;
}

std::istream& operator>> (std::istream& in, Employer& employer) {

	printf("Input wage:\n");
	in >> employer.wage;

	return in;
}

ostream& operator<< (ostream& out, const Employer& employer)
{
	out << "wage: " << employer.wage << endl;

	return out;
}
