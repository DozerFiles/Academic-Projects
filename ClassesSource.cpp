#include <iostream>
#include <string>
using namespace std;
// Comment
//comment 2
class Customer
{
private:
	string cusName;
	string cusAddress;
	string cusEmail;
	int cusSickDays;
public:
	void setCusName(string);
	string getCusName();
	void setCusAddress(string);
	string getCusAddress();
	void setCusEmail(string);
	string getCusEmail();
	void setCusSickDays(int);
	int getCusSickDays();
	Customer();
};


void Customer::setCusName(string name)
{
	cusName = name;
}
void Customer::setCusAddress(string address)
{
	cusAddress = address;
}
void Customer::setCusSickDays(int SickDays)
{
	cusSickDays = SickDays;
}
void Customer::setCusEmail(string Email)
{
	cusEmail = Email;
}
string Customer::getCusName() { return cusName; }
string Customer::getCusAddress() { return cusAddress; }
string Customer::getCusEmail() { return cusEmail; }
int Customer::getCusSickDays() { return cusSickDays; }



Customer::Customer()
{
	cusName = "";
	cusAddress = "";
	cusEmail = "";
	cusSickDays = 0;
}



void displayMenu(Customer *cus)
{

	cout << cus->getCusName() << ", Choose what information you'd like to verify: " << endl;

	cout << "My Menu";
	cout << "========" << endl;
	cout << "1 - Address on file" << endl;
	cout << "2 - Email Domain on file" << endl;
	cout << "3 - Sick Days Available" << endl;
	cout << "E - Exit" << endl << endl;
}


void viewAddress(Customer *cus)
{
	cout << "Name: " << cus->getCusName() << endl;
	cout << "Your Address: " << cus->getCusAddress() << endl;
}


void viewEmail(Customer *cus)
{
	cout << "Name: " << cus->getCusName() << endl;
	cout << "Your Email Domain: " << cus->getCusEmail() << endl;
}


int SickDays(Customer *cus)
{
	return cus->getCusSickDays();
}


int main(void)
{
	char selection = ' ';
	Customer customer1;
	//string customer1 = "";
	
	customer1.setCusName("Hayden");
	customer1.setCusAddress("9999 Street Ave");
	customer1.setCusEmail("outlook.com");
	customer1.setCusSickDays(7+7);
	cout << "Hello " + customer1.getCusName() << endl;
	


	do
	{
		displayMenu(&customer1);
		cin >> selection;

		switch (selection)
		{
		case '1':
			cout << "Address" << endl;
			viewAddress(&customer1);
			break;
		case '2':
			cout << "Email Domain" << endl;
			viewEmail(&customer1);
			break;
		case '3':
			cout << "Sick Days Available" << endl;
			cout << "You have a total of " << SickDays(&customer1) << " Sick Days Available." << endl;
			break;
		case 'E':
		case 'e':
			cout << "Thank you!" << endl;
			break;
		default: cout << "That isn't on our list of information to verify. Please Select from the list below.";
		}
		cout << endl << endl;
	} while (selection != 'E' && selection != 'e');

	return 0;
}

/*

char selection = ' ';
string name = "";

cout << "What's your name? ==> ";
getline(cin, name);


cout << "Hello! " + name << endl;

string *products;
float *price;
int quantity = 0;

cout << "How many items total will you be needing? ";
cin >> quantity;
products = new string[quantity];
price = new float[quantity];


displayMenu(name);
cin >> selection;

for (int arrayIndex = 0; arrayIndex < quantity; arrayIndex++)
{
	cin.ignore();
	cout << arrayIndex << " - Please enter an item: ";
	getline(cin, products[arrayIndex]);
	cout << "Please enter how many: " << products[arrayIndex] << " ==> ";
	cin >> price[arrayIndex];
}

for (int arrayIndex = 0; arrayIndex < quantity; arrayIndex++)
{
	cout << arrayIndex << " - " << products[arrayIndex] << " Price: " << price[arrayIndex] << endl;

}


delete[]products;
delete[]price;

return 0;

*/
