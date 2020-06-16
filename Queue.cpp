#include <iostream>
#include <cstdlib>
using namespace std;




struct node
{
	int info;
	struct node *next;

};


class Queue
{
private:
	node *rear;
	node *front;
	int count;
public:
	Queue();
	void enqueue();
	void dequeue();
	void display();
	void isempty();
	void dataBack();
	void dataFront();
	void noElements();
};



Queue::Queue()
{
	rear = NULL;
	front = NULL;
	count = 0;
}

void Queue::dataFront()
{
	if (front == NULL)
	{
		cout << "The front queue seems empty" << endl;
	}
	else
	{
		cout << front->info << endl;
	}
}


void Queue::dataBack()
{
	if (rear == NULL)
	{
		cout << "The data in the back seems to be empty" << endl;
	}
	else
	{
		cout << rear->info << endl;
	}
}


void Queue::noElements()
{
	if (count > 0)
	{
		cout << "Hey! i've found " << count << " many items in the queue!" << endl;
	}
	else
	{
		cout << "Seems lonely in here.." << endl;
	}
}


void Queue::enqueue()
{
	int data;
	node *temp = new node;
	cout << "What would you like to add? ";
	cin >> data;
	temp->info = data;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
	}
	rear->next = temp;
	rear = temp;
	count++;
}


void Queue::dequeue()
{
	node *temp = new node;
	if (front == NULL)
	{
		cout << " Queue seems empty" << endl;
	}
	else
	{
		cout << " The Data is " << front->info << endl;
		if (front == rear)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
	}

	count--;
}



void Queue::isempty()
{
	if (front == NULL)
	{
		cout << "Queue is Empty yo" << endl;
	}
	else
	{
		cout << "Its a party in here! Its not empty" << endl;
	}
}


void Queue::display()
{
	node *p = new node;
	p = front;
	if (front == NULL)
	{
		cout << "Sorry, I have nothing to show you " << endl;
	}
	else
	{
		while (p != NULL)
		{
			cout << endl << p->info;
			p = p->next;
		}
	}
}


int main()
{
	Queue queue;
	char choice;
	while (true)
	{
		cout << " \n1. Enqueue\n2. Dequeue\n3. Print Front data\n4. Print Back data\n5. Print Entire queue\n6. is queue empty\n7. Total Number of Elements in queue\n8. Exit";
		cout << "what would you like to do? ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			queue.enqueue();
			break;
		case '2':
			queue.dequeue();
			break;
		case '3':
			queue.dataFront();
			break;
		case '4':
			queue.dataBack();
			break;
		case '5':
			queue.display();
			break;
		case '6':
			queue.isempty();
			break;
		case '7':
			queue.noElements();
			break;
		case '8':
			exit(0);
			break;
		default:
			cout << " Sorry, that's not an option. ";
			break;
		}
	}
	return 0;
}