#include"List.h"
#include<iostream>
using namespace std;

List::List()
{
	head = 0;
	tail = 0;
}

List::~List()
{
	while (head)
	{
		Node* p = head;
		head = p->next;
		delete p;
	}
}

void List::insert(int value)
{
	Node* node = new Node();
	node->value = value;
	node->next = head;
	head = node;
}


void List::print()
{
	Node* p = head;
	while (p != 0)
	{
		printf("%d", p->value);
		p = p->next;
	}
}

void List::createSecondList(List* list1)
{
	int a = this->listLength();
	int* b = new int[a];
	Node* p = head;
	for (int i = 0; i < a; i++)
	{
		b[a-i-1] = p->value;
		p = p->next;
	}
	int max = b[0];
	cout <<"max "<< max<<endl;
	int counter = 0;
	for (int i = 0; i < a; i++)
	{
		if (b[i] == max) { counter++; }
	}
	cout << "num " << counter<< endl;
	int* d = new int[counter];
	int k = 0;
	for (int i = 0; i < a; i++)
	{
		if (b[i] == max) 
		{
			d[k++] = i; 
		}
	}
	for (int i = 0; i < counter; i++)
	{
		list1->insert(d[i]+1);
	}
}

int List::listLength()
{
	Node* p = head;
	int counter = 0;
	while (p->next != NULL)
	{
		p = p->next;
		counter++;
	}
	return counter + 1;
}