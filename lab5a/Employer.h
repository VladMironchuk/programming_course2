#include <string.h>
using namespace std;

class Employer {
protected:
	double wage;
	double salary;
public:
	Employer(double wage) { this->wage = wage;};
	virtual void showJob() = 0;
	virtual void showMoneyPerWorking() = 0;
	friend  std::ostream& operator<< (std::ostream& out, const Employer& employer);
	friend  std::istream& operator>> (std::istream& in, Employer& employer);
};

class Manager : public Employer {
public:
	Manager(double wage) :Employer(wage) { this->salary = 2000; };
	void showJob();
	void showMoneyPerWorking();
};

class Admin : public Employer {
public:
	Admin(double wage) :Employer(wage) { this->salary = 5000; };
	void showJob();
	void showMoneyPerWorking();
};

class Programmer : public Employer {
public:
	Programmer(double wage) :Employer(wage) { this->salary = 8000; };
	void showJob();
	void showMoneyPerWorking();
};

