#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
	Stack<int>* stack = new Stack<int>;
	int k;
	do{
		cout << endl << "1 - Print stack" << endl;
		cout<<"2 - Add elemnt to stack" << endl;
		cout<<"3 - Remove element from stack" << endl;
		cout<<"4 - Get length of stack" << endl;
		cout<<"0 - Exit" << endl;
		cout<<"Input function: ";
		cin >> k;
		cout<<endl;
		switch (k)
		{
		case 1:
			stack->print();
			break;
		case 2:
			int value;
			cout << "Input value you want to add: ";
			cin >> value;
			stack->push(value);
			break;
		case 3:
			stack->pop();
			cout << "Element succesfully removed" << endl;
			break;
		case 4:
			cout << "Length of the stack: " << stack->getSize() << endl;
			break;
		case 0:
			return 0;
		default:
			cout<<"\nThere are no such function" << endl << endl;
			break;
		}
	} while (k);
return 0;
}