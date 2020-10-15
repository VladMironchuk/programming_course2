#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <string.h>
using namespace std;

//констркторы
String::String()
{
	this->setStringLength();
	this->setString();
} //конструктоп по умолчанию

String::String(const String& string1)
{
	this->stringLength = string1.stringLength;
	string = new char[this->stringLength];
	this->string = string1.string;
} //коснструктор копирования

String::~String() {} //деструктор

//методы
void String::setStringLength()
{
	cout << "enter length of string" << endl;
	cin >> stringLength;
	string = new char[stringLength];
} //задаем произвольную длину

void String::setStringLength(int l)
{
	this->stringLength = l;
}//задаем задануую длину 

void String::setString()
{
	cout << "enter a string" << endl;
	cin >> string;
}//вводим произволнуью строку

void String::setString(char* str)
{
	this->string = str;
}//присваиваем строку

String String::stringConcatenation(String string1)
{
	return *this += string1;
} //конкатенация строк

char String::getSymbol(int n)
{
	char* string = this->getString();
	char symbol = string[n - 1];
	//cout << n << " symbol is " << symbol << endl;
	return symbol;
} //извлечение символа

void String::compaireStrings(String string1)
{
	if (*this>string1) { cout << this->getString() << ">" << string1.getString() << endl; }
	else if (*this<string1) { cout << this->getString() << "<" << string1.getString() << endl; }
	else { cout << this->getString() << "=" << string1.getString() << endl; }
} //сравнивание строк

void String::showString()
{
	cout << string << endl;
} //вывод строки

char* String::getString()
{
	return string;
} //извлечение строки

int String::getStringLength()
{
	return stringLength;
} //получение длины строки

//операторы
String String :: operator+(String string1)
{
	int l = stringLength + string1.stringLength;
	char* str = new char[l];
	strcpy(str, string);
	strcat(str, string1.string);
	String str0(str, l);
	return str0;
}//оператор сложения

String& String::operator=(const String string1)
{
	this->stringLength = string1.stringLength;
	string = new char[this->stringLength];
	this->string = string1.string;
	return *this;
} //оператор присваивания

String String::operator+=(String string1)
{
	this->setStringLength(this->getStringLength() + string1.getStringLength());
	strcat(this->getString(), string1.getString());
	return *this;
} //оператор сложения с присваиванием

char& String::operator[](int i)
{
	char* string1 = this->getString();
	if (i <= strlen(string1))
		return string1[i - 1];
	else cout << "error" << endl;

} //оператор индексирования

bool String::operator>(String string1)
{
	if (strlen(this->getString()) > strlen(string1.getString())) { return true; }
	else { return false; }
}//оператор больше

bool String::operator<(String string1)
{
	if (strlen(this->getString()) < strlen(string1.getString())) { return true; }
	else { return false; }
}//оператор меньше

//сортировка
void String::sortMassiveByFirtsLetter(String list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n - 1; k++)
		{
			if (list[k].getSymbol(1) > list[k + 1].getSymbol(1))
			{
				String swap = list[k];
				list[k] = list[k + 1];
				list[k + 1] = swap;
			}
		}
	}
} //сортировка по первой букве

void String::sortMassiveByLengths(String list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n - 1; k++)
		{
			if (strlen(list[k].getString()) > strlen(list[k + 1].getString()))
			{
				String swap = list[k];
				list[k] = list[k + 1];
				list[k + 1] = swap;
			}
		}
	}
} //сортировка по длине