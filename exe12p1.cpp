/*  Created by Maor Frost 206370231 on 2.1.2022.
 *  introduction for cpm-sci - Meir Komar
 *	exercise 10 task 3
 *  virtual lexicon manager
 */

#include <iostream>
using namespace std;

struct Item {
	int pin;
	char pName[21];
	int amount;
	int minimum;
	float price;
};

// sequential-search for Item in database.
int searchItem( Item * database, int dataNumber, int dataSrch)
{
	for (int i = 0; i < dataNumber; i++)
	{
		if (database[i].pin == dataSrch)//if class_code is in database
		{
			return i;//return index to item
		}
	}
	return -1;//else return NULL
}


void addItem(Item *&store,int storeSize, int &inStock)
{
	Item newItem;//declare new item

	cout << "enter code:  \n";
	cin >> newItem.pin;
	cout << "enter name:\n";
	cin.getline(newItem.pName,20);
	cout << "enter amount:\n";
	cin >> newItem.amount;
	cout << "enter minimum amount:\n";
	cin >> newItem.minimum;
	cout << "enter price:\n";
	cin >> newItem.price;

	if (inStock < storeSize)//if there is still place for new items
	{
		int found=searchItem(store,inStock,newItem.pin);//finding new item in store
		if(found>-1)//if found
		{
			if(strcmp(store[found].pName,newItem.pName)==0)//if the name is the same as in store
			{
				store[found].amount += newItem.amount;//add amount
				store[found].minimum = newItem.minimum;//reset minimum
				store[found].price = newItem.price;//reset price
			}
			else cout << "ERROR" << endl;
		}
		else
		{
			++inStock;//increase in store item number


		}


		int pin;
		//asking from user to enter Item details
		cout << "" << endl;

		cin >> pin;

		if (!found)
		{

			cin.getline(store[inStock].pName, 20);
			cin >> store[inStock].minimum >> store[inStock].price;
		}
		else


			cin >> numToAdd;
			store[found].inStock+=numToAdd;

	}
	else
		cout <<"ERROR"<<endl;
}//end of addItem

void findPrice(Item *store, int numItems)//printing price of item
{int pin,index;
//getting pin of item from user
cout << "" << endl;
cin>>pin;
//getting index of item
index = searchItem(store,numItems,pin);
//if the item found, printing price of item
if(index!=NULL)
	cout << store[index].price << endl;
else
	cout << "ERROR"<<endl;
}

void sold(Item *store, int numItems)//updating stock of item
{
int pin,numSold;
//getting pin of item from user
	cout << "" << endl;
	cin>>pin;
//getting number of sold items from user
	cout << "" << endl;
	cin>>numSold;

//getting index of item
int index = searchItem(store,numItems,pin);

if(store[index].amount>numSold && index > -1 )//if there is number of items in stock more then sold
	store[index].amount-=numSold;//updating number of item in stock
else
	cout << "ERROR"<<endl;
}

void order(Item *store, int numItems)//updating stock of every item in store
{
	//for every item in store
	for (int i = 0; i < numItems; ++i)
	{
		if(store[i].amount<store[i].minimum)//if amount is less than minimum
		{//printing mame of item and amount to order
			cout << store[i].pName << " " << (store[i].minimum + 5) - store[i].amount << endl;
			store[i].amount += (store[i].minimum + 5) - store[i].amount;//update amount after order
		}
	}
}



void print(Item *store, int numItems)
{

}

//main function
enum cases{EXIT,ADD,FIND,SOLD,ORDER,PRINT};
int main()
{
	Item* store;
	int maxItems;
	int numItems = 0;
	int choice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;
	store = new Item[maxItems];

	do {
		cout << "enter 0-5:\n";

		cin >> choice;

		switch (choice) {
			case EXIT:	break;

			case ADD:	addItem(store, maxItems, numItems);
				break;

			case FIND: 	findPrice(store, numItems);
				break;

			case SOLD:	sold(store, numItems);
				break;

			case ORDER:	order(store, numItems);
				break;

			case PRINT: 	print(store, numItems);
				break;

			default: 	cout << "ERROR" << endl;
		}
	} while (choice != 0);
	return 0;
}
