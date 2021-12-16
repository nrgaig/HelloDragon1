/*  Created by Maor Frost 206370231 on 16/12/2021.
 *  introduction for cpm-sci - Meir Komar
 *	exercise 9 task 1
 *  class manager for institute with hybrid classes.
 *  Now, with dynamic array allocation.
 */

#include <iostream>

using namespace std;

//printing all classes in database
void printAll(const int *database, int current_size)
{
	if (current_size)
	{
		for (int i = 0; i < current_size; i++)//for each element in database
		{
			cout << *(database + i) << " ";//print it
		}
		cout << endl;//after printing - new line
	}
}

// pointer base insertion sort - sorts the first n elements of arr in ascending order
void insertionSort(int *arr, int size)
{
	int i;
	for (int first = 1; first < size; first++)
	{
		int tmp = *(arr + first);
		for (i = first; i > 0 && tmp < (*(arr + i - 1)); --i)
		{
			*(arr + i) = *(arr + i - 1);
		}
		*(arr + i) = tmp;
	}
}// end insertionSort

//adding new class to database
void newClass(int *&database, int &current_size, int new_class)
{
	if (current_size == 0)//if there is no array pointing to
	{
		database = new int[1];//crating new array size 1
		*database = new_class;// inserting value of first class to new array
		current_size++;
	}
	else
	{
		bool not_found = true;//flag for new class not found in database

		for (int i = 0; i < current_size; i++)// approving the new_class is not already in database
		{
			if (*(database + i) == new_class)//if new_class is already in database
			{
				not_found = false;//not_found be false
			}
		}

		if (not_found)//if new class not found in database - add class to database
		{
			current_size++; // step 3 - increase size of database (new size)
			int *tmp = new int[current_size];// step 4 - allocating tmp array to save old values and add the new one

			for (int i = 0; i < current_size - 1; i++)
			{
				*(tmp + i) = *(database + i); // step 5 - copping relevant data
			}
			*(tmp + current_size - 1) = new_class; // adding new_class to new array database

			delete[] database;                        // step 6 - deleting old database array
			database = tmp;                            // step 7 - pointing to tmp array as new database

			insertionSort(database, current_size);//sort database
		}
	}
}

void delCass(int *&database, int &current_size, int class_num)//deleting class from database
{
	if (current_size == 0)
	{
		cout << "ERROR" << endl;
	}
	else if (current_size == 1)
	{
		delete[]database;//deleting the database
		current_size--;
	}
	else
	{
		int *p_database;
		bool found = false;

		for (int i = 0; i < current_size; i++)// approving the class_num is in database
		{
			if (*(database + i) == class_num)//if class_num is in database
			{
				found = true;//found be true
				p_database = (database + i);//pointer to memory of class_num
				break;
			}
		}

		if (found)//if class_num is found in database
		{
			*p_database = 99999;//make it be largest for the sort as deleting it

			insertionSort(database, current_size);//sorting

			current_size--; // step 3 - decrease size of database (new size)
			int *tmp = new int[current_size];// step 4 - allocating tmp array to save old values and add the new one

			for (int i = 0; i < current_size; i++)
			{
				*(tmp + i) = *(database + i); // step 5 - copping relevant data
			}

			delete[] database;         // step 6 - deleting old database array
			database = tmp;            // step 7 - pointing to tmp array as new database
		}
	}
}

// sequential-search for class in database.
const int *searchClass(const int *database, int classesNumber, int class_code)
{
	for (int i = 0; i < classesNumber; i++)
	{
		if (*(database + i) == class_code)//if class_code is in database
		{
			return (database + i);//return pointer to it
		}
	}
	return NULL;//else return NULL
}

//printing all classes in Campus
void printCode(const int *database, int current_size, int campus_code)
{
	//for each class in database
	for (int i = 0; i < current_size; i++)
	{
		if ((*(database + i) / 1000) == campus_code)
		{
			cout << *(database + i) << " ";
		}
	}
	cout << endl;
}

//main function
int main()
{
	int *database, database_size = 0, input = 0;
	enum Choice
	{
		NEW,
		DEL,
		SRCH,
		PRNT_COD,
		PRNT_ALL,
		EXT
	};

	//asking from the user to enter choice
	cout << "Enter 0 to add a new classroom.\n"
	        "Enter 1 to delete a hybrid classroom.\n"
	        "Enter 2 to search for a specific classroom.\n"
	        "Enter 3 to print all the classrooms for a specific Machon.\n"
	        "Enter 4 to print all the hybrid classrooms.\n"
	        "Enter 5 to exit.\n"
	        "Enter your choice:"
	     << endl;
	cin >> input;

	while (input != EXT)
	{
		switch (input)//switch
		{
			case NEW://add new class to database
				cout << "Enter the code of the classroom to add:" << endl;//asking to enter class code to add
				cin >> input;
				while (input > 99999 || input < 10000)
				{
					cout << "ERROR" << endl;
					cin >> input;
				}
				newClass(database, database_size, input);//adding class code to database
				printAll(database, database_size);//print all class in database
				break;

			case DEL:                                                        //delete class from database
				cout << "Enter the code of the classroom to delete:" << endl;//asking to enter class code to delete
				cin >> input;
				while (input > 99999 || input < 10000)
				{
					cout << "ERROR" << endl;
					cin >> input;
				}
				delCass(database, database_size, input);//deleting class from database
				printAll(database, database_size);//print all class in database
				break;

			case SRCH://search class in database
				cout << "Enter the code of the classroom to search for:"
				     << endl;//asking to enter class code to delete
				cin >> input;
				while (input > 99999 || input < 10000)
				{
					cout << "ERROR" << endl;
					cin >> input;
				}
				//if searchClass returns something is not NULL means it found in database
				if (searchClass(database, database_size, input) != NULL)
				{
					cout << "Found" << endl;
				}
				else
				{
					cout << "not found" << endl;
				}
				break;

			case PRNT_COD://print all class in campus_code
				cout << "Enter the code of the Machon:" << endl;
				cin >> input;
				while (input > 99 || input < 10)
				{
					cout << "ERROR" << endl;
					cin >> input;
				}
				printCode(database, database_size, input);
				break;

			case PRNT_ALL://print all class in database
				printAll(database, database_size);
				break;

			default://default case
				cout << "ERROR" << endl;
				break;
		}

		//asking from user input for next choice
		cout << "Enter your next choice:" << endl;
		cin >> input;
	}
	delete[]database;//deleting database from dynamic memory
	return 0;
}
/* run sample:
 *
Enter 0 to add a new classroom.
Enter 1 to delete a hybrid classroom.
Enter 2 to search for a specific classroom.
Enter 3 to print all the classrooms for a specific Machon.
Enter 4 to print all the hybrid classrooms.
Enter 5 to exit.
Enter your choice:
0
Enter the code of the classroom to add:
11111
11111
Enter your next choice:
0
Enter the code of the classroom to add:
22222
11111 22222
Enter your next choice:
0
Enter the code of the classroom to add:
33333
11111 22222 33333
Enter your next choice:
0
Enter the code of the classroom to add:
44444
11111 22222 33333 44444
Enter your next choice:
0
Enter the code of the classroom to add:
55555
11111 22222 33333 44444 55555
Enter your next choice:
0
Enter the code of the classroom to add:
22444
11111 22222 22444 33333 44444 55555
Enter your next choice:
0
Enter the code of the classroom to add:
55432
11111 22222 22444 33333 44444 55432 55555
Enter your next choice:
0
Enter the code of the classroom to add:
12345
11111 12345 22222 22444 33333 44444 55432 55555
Enter your next choice:
1
Enter the code of the classroom to delete:
22444
11111 12345 22222 33333 44444 55432 55555
Enter your next choice:
1
Enter the code of the classroom to delete:
33333
11111 12345 22222 44444 55432 55555
Enter your next choice:
2
Enter the code of the classroom to search for:
12345
Found
Enter your next choice:
2
Enter the code of the classroom to search for:
33333
not found
Enter your next choice:
3
Enter the code of the Machon:
55
55432 55555
Enter your next choice:
4
11111 12345 22222 44444 55432 55555
Enter your next choice:
5

Process finished with exit code 0
 */
