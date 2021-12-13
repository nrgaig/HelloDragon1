/*  Created by Maor Frost 206370231 on 09/12/2021.
 *  introduction for cpm-sci - Meir Komar
 *	exercise 8 task 1
 *  getting numbers to 2 arrays from the user
 *  print minimal skip value of small in big.
 */

#include <iostream>

using namespace std;

const int SIZE = 80;// size of array


int min_gap(int *big, const int *small, int big_size, int small_size)//another try to solve the problem
{
	int i, skip;
	int *p_big_first = big;

	if (small_size == 1)//search for lone number
	{
		for (i = 0; i < big_size; i++)//find first small in big
		{
			if (*(big + i) == *small)
				return 0;

		}
		return -1;
	}


	for (skip = 0; skip < big_size; skip++)//search if the skip is existing in big
	{
		for (i = 0; i < big_size; i++)//find first small in big
		{
			//finding first small in big
			if (*(big + i) == *small)
			{
				p_big_first = big + i;
				break;
			}
		}

		// checking if rest of small appears in the same skip
		for (i = 1; i < small_size; i++)//find the next small in big
		{
			//ensure that the rest of element in small appears in the same skip
			if (*(p_big_first + skip * i) != *(small + i))
				break;
		}

		if (i == small_size)// if we get to end of size means it appears in our skip
			return skip - 1;

	}

	return -1;//if not found in any skip return -1

}


//initiate arrays with 0 for GCC
void array_init(int arr[], int maxsize = SIZE)
{
	for (int *p_arr = arr; p_arr - arr < maxsize; p_arr++)
	{
		*p_arr = 0;
	}
}

void insertion(int arr[], int maxsize = SIZE)//insert values to an array
{
	// assumes input is correct
	for (int *p_arr = arr; p_arr - arr < maxsize; p_arr++)// for every member of arr
	{
		cin >> *p_arr;// input to array member using its pointer
	}

}

//main function.
int main()
{

	int big[SIZE], small[SIZE], big_size, small_size;


	for (int element: big)//initiate arrays with 0 for GCC
	{
		element = 0;
	}
	for (int element: small)//initiate arrays with 0 for GCC
	{
		element = 0;
	}


	cout << "Enter the size of big:" << endl;// asking from user enter size for big
	cin >> big_size;

	cout << "Enter " << big_size << " numbers:" << endl;// asking from user enter numbers for big
	insertion(big, big_size);

	cout << "Enter the size of small:" << endl;// asking from user enter size for small
	cin >> small_size;

	cout << "Enter " << small_size << " numbers:" << endl;// asking from user enter numbers for small
	insertion(small, small_size);


	cout << "Size of jump:" << endl;

	cout << min_gap(big, small, big_size, small_size) << endl;

}
