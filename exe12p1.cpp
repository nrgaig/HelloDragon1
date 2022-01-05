/*  Created by Maor Frost 206370231 on 2.1.2022.
 *  introduction for cpm-sci - Meir Komar
 *	exercise 12 task 1
 *  store manager with structs
 */

#include <iostream>
#include <cstring>

using namespace std;

struct Item
{
	int pin;
	char pName[21];
	int amount;
	int minimum;
	float price;
};

// sequential-search for Item in database.
int searchItem(Item *database, int dataNumber, int dataSrch)
{
	for (int i = 0; i < dataNumber; i++)
	{
		if (database[i].pin == dataSrch)//if class_code is in database
		{
			return i;//return index to item
		}
	}
	return -1;//else return -1
}


void addItem(Item *&store, int storeSize, int &inStock)
{
	Item newItem{};//declare new item

	cout << "enter code:  \n";
	cin >> newItem.pin;
	cout << "enter name:\n";
	cin.get();
	cin.getline(newItem.pName, 20);
	cout << "enter amount:\n";
	cin >> newItem.amount;
	cout << "enter minimum amount:\n";
	cin >> newItem.minimum;
	cout << "enter price:\n";
	cin >> newItem.price;

	if (inStock <= storeSize)//if there is still place for new items
	{
		int found = searchItem(store, inStock, newItem.pin);//finding new item in store

		if (found > -1)//if found
		{
			if (strcmp(store[found].pName, newItem.pName) == 0)//if the name is the same as in store
			{
				store[found].amount += newItem.amount;//add amount
				store[found].minimum = newItem.minimum;//reset minimum
				store[found].price = newItem.price;//reset price
			}
			else
			{ cout << "ERROR" << endl; }
		}
		else// if item not found
		{
			if(inStock < storeSize)
			{
				store[inStock] = newItem;//add new item to store
				++inStock;//increase inStock value
			}
			else
				cout << "ERROR" << endl;

		}
	}
	else
	{
		cout << "ERROR" << endl;
	}
}//end of addItem

void findPrice(Item *store, int numItems)//printing price of item
{
	int pin, index;
//getting pin of item from user
	cout << "enter code:" << endl;
	cin >> pin;
//getting index of item
	index = searchItem(store, numItems, pin);
//if the item found, printing price of item
	if (index > -1)
	{
		cout << "price:" << store[index].price << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}
}

void sold(Item *store, int numItems)//doing sell - updating stock of item
{
	int pin, numSold;
//getting pin of item from user
	cout << "enter code: " << endl;
	cin >> pin;
//getting number of sold items from user
	cout << "enter amount:" << endl;
	cin >> numSold;

//getting index of item
	int index = searchItem(store, numItems, pin);

	if (index > -1)//if item found
	{
		if (store[index].amount > numSold)
		{//if there is number of items in stock more than sold
			store[index].amount -= numSold;//updating number of item in stock
		}
		else
		{
			store[index].amount = 0;
		}
	}
	else//if nor found peint error
	{
		cout << "ERROR" << endl;
	}
}

void order(Item *store, int numItems)//updating stock of every item in store
{
	//for every item in store
	for (int i = 0; i < numItems; ++i)
	{
		if (store[i].amount < store[i].minimum)//if amount is less than minimum
		{//printing mame, code and amount to order of item
			cout << "item name: " << store[i].pName << "\ncode: " << store[i].pin << "\namount to order: " <<
			     (store[i].minimum + 5) - store[i].amount << endl;
			store[i].amount += (store[i].minimum + 5) - store[i].amount;//update amount after order
		}
	}
}


void print(Item *store, int numItems)//printing every item in store
{
	for (int i = 0; i < numItems; ++i)//for every item in store
	{
		cout << "name: " << store[i].pName << "\n" <<
		     "code: " << store[i].pin << "\n" <<
		     "amount: " << store[i].amount << "\n" <<
		     "minimum amount: " << store[i].minimum << "\n" <<
		     "price:" << store[i].price << endl << endl;

	}
}


enum cases
{
	EXIT, ADD, FIND, SOLD, ORDER, PRINT
};
//main function copied from assignment word file
int main()
{
	Item *store;
	int maxItems;
	int numItems = 0;
	int choice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;
	store = new Item[maxItems];

	do
	{
		cout << "enter 0-5:\n";

		cin >> choice;

		switch (choice)
		{
			case EXIT:
				break;

			case ADD:
				addItem(store, maxItems, numItems);
				break;

			case FIND:
				findPrice(store, numItems);
				break;

			case SOLD:
				sold(store, numItems);
				break;

			case ORDER:
				order(store, numItems);
				break;

			case PRINT:
				print(store, numItems);
				break;

			default:
				cout << "ERROR" << endl;
		}
	}
	while (choice != 0);
	return 0;
}// end of main

//enter max number of items:
//30
//enter 0-5:
//1
//enter code:
//1111
//enter name:
//asdf1
//		enter amount:
//8
//enter minimum amount:
//5
//enter price:
//3.45
//enter 0-5:
//1
//enter code:
//2222
//enter name:
//tabs
//		enter amount:
//10
//enter minimum amount:
//5
//enter price:
//10
//enter 0-5:
//1
//enter code:
//0000
//enter name:
//backspases
//		enter amount:
//30
//enter minimum amount:
//10
//enter price:
//0
//enter 0-5:
//5
//name: asdf1
//		code: 1111
//amount: 8
//minimum amount: 5
//price:3.45
//
//name: tabs
//		code: 2222
//amount: 10
//minimum amount: 5
//price:10
//
//name: backspases
//		code: 0
//amount: 30
//minimum amount: 10
//price:0
//
//enter 0-5:
//2
//enter code:
//2222
//price:10
//enter 0-5:
//3
//enter code:
//1111
//enter amount:
//5
//enter 0-5:
//4
//item name: asdf1
//		code: 1111
//amount to order: 7
//enter 0-5:
//4
//enter 0-5:
//5
//name: asdf1
//		code: 1111
//amount: 10
//minimum amount: 5
//price:3.45
//
//name: tabs
//		code: 2222
//amount: 10
//minimum amount: 5
//price:10
//
//name: backspases
//		code: 0
//amount: 30
//minimum amount: 10
//price:0
//
//enter 0-5:
//0
