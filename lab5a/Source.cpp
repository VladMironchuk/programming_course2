#include "Employer.h"
#include <iostream>
using namespace std;
int main() {
	Manager manager(10);
	manager.showJob();
	manager.showMoneyPerWorking();
	cout << manager;
	cin >> manager;
	cout << manager;
	return 0;
}