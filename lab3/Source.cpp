#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List list, list1;
	list.insert(6);
	list.insert(6);
	list.insert(1);
	list.insert(1);
	list.insert(5);
	list.insert(6);
	list.print();
	cout << endl;
	list.createSecondList(&list1);
	list1.print();
	return 0;
}