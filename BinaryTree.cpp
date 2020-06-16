#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void loadfile();
void insertData();



struct binaryNode
{
	int productcode;
	string productname;
	string productversion;
	string productprice;
	binaryNode* left;
	binaryNode* right;
	binaryNode* parent;	
};



binaryNode* newNode(int packingCode, string packingName, string packingVersion, string packingPrice)
{
	binaryNode* newNode = new binaryNode();
	newNode->productcode = packingCode;
	newNode->productname = packingName;
	newNode->productprice = packingPrice;
	newNode->productversion = packingVersion;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	return newNode;
}


binaryNode* insert(binaryNode* rootPoint, int packingCode, string packingName, string packingPrice, string packingVersion)
{
	static binaryNode *p;
	binaryNode *returnNode;


	if (rootPoint == NULL)
	{
		returnNode = newNode(packingCode, packingName, packingPrice, packingVersion);
			returnNode->parent = p;
		return returnNode;
	}

	if (packingCode <= rootPoint->productcode)
	{
		p = rootPoint;
		rootPoint->left = insert(rootPoint->left, packingCode, packingName, packingPrice, packingVersion);
	}

	else
	{
		p = rootPoint;
		rootPoint->right = insert(rootPoint->right, packingCode, packingName, packingPrice, packingVersion);
	}
	return rootPoint;
}

binaryNode* rootpointer = NULL;


bool search(binaryNode* rootPoint, int productcode)
{

	if (rootPoint == NULL)
	{
		return false;
	}

	else if (rootPoint->productcode == productcode)
	{
		return true;
	}

	else if (productcode <= rootPoint->productcode)
	{
		return search(rootPoint->left, productcode);
	}

	else
	{
		return search(rootPoint->right, productcode);
	}
}


struct binaryNode* Delete(struct binaryNode *rootpointer, int productcode)
{
	if (rootpointer == NULL)
	{
		return rootpointer;
	}

	else if (productcode < rootpointer->productcode)
		rootpointer->left = Delete(rootpointer->left, productcode);
	
	else if (productcode < rootpointer->productcode)
		rootpointer->right = Delete(rootpointer->right, productcode);

	else
	{
		if (rootpointer->left == NULL && rootpointer->right == NULL)
		{
			delete rootpointer;
			rootpointer = NULL;
		}

		else if (rootpointer->left == NULL)
		{
			struct binaryNode *temp = rootpointer;
			rootpointer = rootpointer->left;
			delete temp;
		}
	}
	return rootpointer;
}


int main()
{
	ofstream software;
	software.open("menu.txt");
	software << "Snipping Tool";
	software << " Word or Excel";
	software << "Google Chrome";
	software.close();
	loadfile();
	bool breakLoop = false;
	int userInput;

	while (breakLoop == false)
	{
		cout << "Menu for Softwares!" << endl;
		cout << "1. Add on New Software\n";
		cout << "2. Delete a software we have\n";
		cout << "3. Search the Menu\n";
		cout << "4. We'er all set, we'll exit\n";
		cin >> userInput;
		system("CLS");
	}

	switch (userInput)
	{
	case 1:
		insertData();
		loadfile();
		break;
	case 2:
		int deleteProduct;
		cout << "Here are your options\n";
		cout << "Product code" << deleteProduct << " is all cleaned up!/n";
		system("Paused");
		system("CLS");
		break;
	case 3:
		int productnumber;
		cout << "Menu\n";
		cout << "Packing number";
		cin >> productnumber;
		system("CLS");

		if (search(rootpointer, productnumber) == true)
		{
			cout << "Packign Number" << productnumber << " is here!/n";
			system("pause");
			system("CLS");
		}

		else (search(rootpointer, productnumber) == false);
		{
			cout << "Packing Number" << productnumber << " doesn't look like its here/n";
			system("pause");
			system("CLS");
		}

	case 4:
		cout << "Menu\n";
		cout << "Goodbye!";
		exit(1);
		break;

	default:
		cout << "Sorry thats not a valid option";
		system("pause");
		system("CLS");
		break;
	}
	return 0;
}


void loadfile()
{
	string loadProductVersion, loadProductPrice;
	int loadProductCode;
	int loadProductName;
	ifstream software("menu.txt");
	if (software.is_open())
	{

		while (software >> loadProductCode >> loadProductName >> loadProductVersion >> loadProductPrice)
		{
			rootpointer = insert(rootpointer, loadProductName, loadProductCode, loadProductVersion, loadProductPrice);
		}
		software.close();
	}

	else
	{
		cout << "menu\n";
		cout << "I can't seem to locate your file";
		system("pause");
		system("CLS");
	}
}

void insertData()
{
	ofstream software("menu.txt", ios::app);
	string userInput;
	if (software.is_open())
	{
		cout << "menu\n";
		cin >> userInput;
		software << userInput << endl;
		system("CLS");

		cout << "menu\n";
		cout << "Product name";
		cin >> userInput;
		software << userInput << endl;


		int i, j = 0;
		for (i = 0; userInput[i] != '\0'; ++i)
		{
			if (userInput[i] != ' ')
				userInput[j++] = userInput[i];
		}
		userInput[j] = '\0';

		software << userInput << endl;
		system("CLS");

		cout << "Menu";
		cout << "Product Version";
		cin.sync();
		cin >> userInput;
		software << userInput << endl;
		system("CLS");

		software.close();
	}

	else
	{
		cout << "Menu" << endl;
		cout << "Sorry, I can't seem to locate your file";
		system("pause");
		system("CLS");
	}
}
