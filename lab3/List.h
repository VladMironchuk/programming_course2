struct Node
{
	int value;
	Node* next;
};

class List
{
private:
	Node* head;
	Node* tail;
public:
	List();
	~List();
	void insert(int value);
	void print();
	void createSecondList(List* list1);
	int listLength();
};