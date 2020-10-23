#include "Employer.h"
#include <iostream>

using namespace std;
int main() {
	Manager manager(10);
	Admin admin(10);
	Programmer programmer(10);
	manager.showJob();
	manager.moneyPerLife();
	admin.showJob();
	admin.moneyPerLife();
	programmer.showJob();
	programmer.moneyPerLife();
	return 0;
}