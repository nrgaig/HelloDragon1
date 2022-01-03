/*  Created by Maor Frost 206370231 on 16/12/2021.
 *  introduction for cpm-sci - Meir Komar
 *	exercise 10 task 3
 *  virtual lexicon manager
 */

#include <iostream>
#include <cstring>
#include<string>

using namespace std;

//printing all words in database
void printAll(char **database, int current_size)
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

// sequential-search for word in database.
char **searchStr(char **database, int size, const char *word)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(*(database + i), word) == 0)//if word_code is in database
		{
			return (database + i);//return pointer to it
		}
	}
	return NULL;//else return NULL
}

// pointer base insertion sort - sorts the first n elements of arr in ascending order
void insertionSort(char **arr, int size)
{
	int i;
	for (int first = 1; first < size; first++)
	{
		char *tmp = *(arr + first);
		for (i = first; i > 0 && strcmp(tmp, *(arr + i - 1)) < 0; --i)
		{
			*(arr + i) = *(arr + i - 1);
		}
		*(arr + i) = tmp;
	}
}// end insertionSort

//adding new word to database
void newStr(char **&database, int &current_size, char *new_word)
{
	if (!current_size)//if there is no array pointing to
	{
		database = new char *[1];//crating new array size 1
		*database = new char[strlen(new_word)];
		strcpy(*database, new_word);// inserting value of first word to new array
		current_size++;
	}
	else
	{
		//if new word not found in database - add word to database
		if (searchStr(database, current_size, new_word) ==NULL)
		{
			current_size++; // step 3 - increase size of database (new size)
			char **tmp = new char *[current_size];// step 4 - allocating tmp array to save old values and add the new
			// one

			for (int i = 0; i < current_size - 1; ++i)//initiate the strings
			{
				*(tmp + i) = new char[strlen(*(database + i))];

			}

			for (int i = 0; i < current_size - 1; i++)
			{
				strcpy(*(tmp + i), *(database + i)); // step 5 - copping relevant data
			}
			*(tmp + current_size - 1) = new char[strlen(new_word)];//creating new string in end of tmp
			strcpy(*(tmp + current_size - 1), new_word);// adding new_word to new array database


			delete[] database;                        // step 6 - deleting old database array
			database = tmp;                            // step 7 - pointing to tmp array as new database

			insertionSort(database, current_size);//sort database
		}
	}
}

//deleting word from lexicon
void delStr(char **&database, int &current_size, char *word)
{
	if(current_size==1&&strcmp(*database, word) == 0)//if size is only one member in database
	{
		delete[]database;//deleting database
		current_size--;//decrease size of database
	}
	else if(current_size>1)
	{
		for (char **p_database = database; p_database < database + current_size - 1; p_database++)
		{
			if (strcmp(*p_database, word) == 0) //if word found in database
			{
				char **tmp;//declaring tmp pointer

				for (tmp = p_database; tmp < database + current_size - 1; tmp++)// for every word from p_database to end
					// of database
				{
					*tmp = *(tmp + 1);//replace with the next
				}
			}
		}
		current_size--;//decrease size of database
		insertionSort(database, current_size);// sort the array
	}
}

//printing all words in lexicon
void printChar(char **database, int current_size, char letter)
{
	//for each word in database
	for (int i = 0; i < current_size; i++)
	{
		if (*(database + i)[0] == letter)
		{
			cout << *(database + i) << " ";
		}
	}
	cout << endl;
}

//main function
int main()
{
	char **lexicon, word[81];
	int lexicon_size = 0, input;
	enum Choice
	{
		NEW,
		DEL,
		SRCH,
		PRNT_CHR,
		PRNT_ALL,
		EXT
	};

	//asking from the user to enter choice
	cout << "Enter 0-5:" << endl;
	cin >> input;
	cin.get();

	while (input != EXT)
	{
		switch (input)//switch
		{
			case NEW://add new word to lexicon
				cout << "Enter the word:" << endl;//asking to enter word code to add
				cin.getline(word, 80);

				newStr(lexicon, lexicon_size, word);//adding word code to lexicon
				printAll(lexicon, lexicon_size);//print all word in lexicon
				break;

			case DEL:                                                        //delete word from lexicon
				cout << "Enter the word to delete:" << endl;//asking to enter word code to delete
				cin.getline(word, 80);

				delStr(lexicon, lexicon_size, word);//deleting word from lexicon
				printAll(lexicon, lexicon_size);//print all word in lexicon
				break;

			case SRCH://search word in lexicon
				cout << "Enter the word to search for:" << endl;//asking to enter word to search
				cin.getline(word, 80);

				//if searchStr returns something is not NULL means it found in lexicon
				if (searchStr(lexicon, lexicon_size, word) != NULL)
				{
					cout << "Found" << endl;
				}
				else
				{
					cout << "not found" << endl;
				}
				break;

			case PRNT_CHR://print all word in campus_code
				cout << "Enter the char:" << endl;
				char letter;
				cin.get(letter);

				printChar(lexicon, lexicon_size, letter);
				break;

			case PRNT_ALL://print all word in lexicon
				printAll(lexicon, lexicon_size);
				break;

			default://default case
				cout << "ERROR" << endl;
				break;
		}

		input = 6;
		//asking from user input for next choice
		cout << "Enter 0-5:" << endl;
		cin >> input;
		cin.get();
	}
	delete[]lexicon;//deleting lexicon from dynamic memory
	return 0;
}

//
//Enter 0-5:
//0
//Enter the word:
//avidab
//		avidab
//Enter 0-5:
//0avidan
//Enter the word:
//avidab vidan
//Enter 0-5:
//0\0
//Enter the word:
//0 avidab vidan
//Enter 0-5:
//0
//Enter the word:
//\
//0 \ avidab vidan
//Enter 0-5:
//0
//Enter the word:
//\\
//0 \ \\ avidab vidan
//Enter 0-5:
//0\0
//Enter the word:
//0 \ \\ avidab vidan
//Enter 0-5:
//0
//Enter the word:
//\0 \0\
//0 \ \0 \0\ \\ avidab vidan
//Enter 0-5:
//1
//Enter the word to delete:
//\
//0 \0 \0\ \\ avidab vidan
//Enter 0-5:
//1
//Enter the word to delete:
//0
//\0 \0\ \\ avidab vidan
//Enter 0-5:
//4
//\0 \0\ \\ avidab vidan
//Enter 0-5:
//3
//Enter the char:
//a
//		avidab
//Enter 0-5:
//6
//ERROR
//		Enter 0-5:
//5
