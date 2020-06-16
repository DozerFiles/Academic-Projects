#include <iostream>
#include <cstdlib>

using namespace std;


class List
{
private:
	typedef struct node 
	{
		int data;
		node* next;
	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;


public: 
	List();
	void AddNode(int addData);
	void DeleteNode(int delData);
	void PrintList();
};

List::List() 
{
	head = NULL;
	curr = NULL;
	temp = NULL;

}

void List::AddNode(int addData)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}

}


int main(int argc, char** argv)
{
	List Books;

	Books.AddNode(3);
	Books.AddNode(5);
	Books.AddNode(7);
	Books.PrintList();

	Books.DeleteNode(5);
	Books.PrintList();

	return 0;
	
}


void List::DeleteNode(int delData)
{
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << delData << " Not within list\n";
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The book " << delData << " has been removed \n";
	}
}


void List::PrintList()
{
	curr = head;
	while (curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}




//Below is the First LinkedList
/*
class Node
{
public:
	Node* next;
	int data;
};

using namespace std;

class LinkedList
{
public:
	int length;
	Node* head;

	LinkedList();
	~LinkedList();
	void add(int data);
	void print();
};

LinkedList::LinkedList() {
	this->length = 0;
	this->head = NULL;
}

LinkedList::~LinkedList() {
	std::cout << "LIST DELETED";
}

void LinkedList::add(int data) {
	Node* node = new Node();
	node->data = data;
	node->next = this->head;
	this->head = node;
	this->length++;
}

void LinkedList::print() {
	Node* head = this->head;
	int i = 1;
	while (head) {
		std::cout << i << ": " << head->data << std::endl;
		head = head->next;
		i++;
	}
}

int main(int argc, char const *argv[])
{
	LinkedList* list = new LinkedList();
	for (int i = 0; i < 100; ++i)
	{
		list->add(rand() % 100);
	}
	list->print();
	std::cout << "List Length: " << list->length << std::endl;
	delete list;
	return 0;
}

*/