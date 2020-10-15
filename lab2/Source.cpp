#include <iostream>
#include "String.h"
using namespace std;
int main()
{
	String* string;
	cout << "enter a number of strings" << endl;
	int n;
	cin >> n;
	string = new String[n];
	int k = 1;
	while (k)
	{
		cout << "choose an operation :" << endl
			<< "1 - concatenation" << endl
			<< "2 - any symbol of the string" << endl
			<< "3 - compairing strings" << endl
			<< "4 - sorting by 1 symbol" << endl
			<< "5 - sorting by the lengths of strings" << endl
			<< "6 - output of given string" << endl
			<< "7 - cheking of indexation" << endl
			<< "0 - exit" << endl;
		cout << "operation : "; cin >> k;
		cout << endl;
		switch (k)
		{
		case 1:
			cout << "choose indexes of 2 strings" << endl;
			int str1_1, str1_2;
			cin >> str1_1;
			cin >> str1_2;
			string[str1_1].stringConcatenation(string[str1_2]);
			string[str1_1].showString();
			cout << endl;
			break;
		case 2:
			cout << "choose an index of the string" << endl;
			int str2_1;
			cin >> str2_1;
			cout << "choose a number of symbol" << endl;
			int symb;
			cin >> symb;
			cout << string[str2_1].getSymbol(symb) << endl << endl;
			break;
		case 3:
			cout << "choose indexes of 2 strings" << endl;
			int str3_1, str3_2;
			cin >> str3_1;
			cin >> str3_2;
			string[str3_1].compaireStrings(string[str3_2]);
			cout << endl;
			break;
		case 4:
			cout << "sorting by 1 letter" << endl;
			string->sortMassiveByFirtsLetter(string, n);
			for (int i = 0; i < n; i++) { cout << string[i].getString() << endl; }
			cout << endl;
			break;
		case 5:
			cout << "sorting by the lenghts of string" << endl;
			string->sortMassiveByLengths(string, n);
			for (int i = 0; i < n; i++) { cout << string[i].getString() << endl; }
			cout << endl;
			break;
		case 6:
			cout << "enter an index of the string" << endl;
			int str6;
			cin >> str6;
			string[str6].showString();
			break;
		case 7:
			cout << "enter an index of the string from class String" << endl;
			int str7_1, str7_2;
			cin >> str7_1;
			cout << "enter an index of the obtain string" << endl;
			cin >> str7_2;
			cout << string[str7_1][str7_2] << endl;
			break;
		}
	}
	delete[] string;
	return 0;
}