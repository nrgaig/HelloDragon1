/*  Created by Maor Frost 206370231 on 09/12/2021.
 *  introduction for cpm-sci - Meir Komar
 *	exercise 8 task 1
 *  getting numbers to 2 arrays from the user
 *  print minimal skip value of small in big.
 */

#include <iostream>
using namespace std;

const int SIZE =80;// size of array

// checking if rest of small appears in the same skip
//parameters: skip range, big[0], small[0], size of bis and small, second elem in big and the nexter
bool is_equal_next_skips(int skip,int const *big,int const *big_size, int *small,int const *small_size, int const *
p_big_second,int const *p_big_next)
{
	int *p_small_third = small + 2;//pointer to third element in small

	while(p_small_third-small<*small_size)//running until end of small
	{

		while (*p_big_next != *p_small_third && p_big_next - big < *big_size)//find the next small in big
			p_big_next++;

		// if current skip different from the first skip or there is no next small in big
		if (p_big_next - p_big_second - 1 != skip || p_big_next - big == *big_size)
		{
		return false;
		}
		// if it is the same skip continue to next
		p_big_second=p_big_next;
		p_big_next++;
		p_small_third++;
	}

	return true;
}


//get two arrays big and small return minimal skip of small in big.
int minSkip(int *big, int *small,int *big_size, int *small_size)
{
	int *p_big_first = big,*p_big_next=&big[1], *p_small = small;
	int skip,minSkip=SIZE;

	if(*small_size==1)//search for lone number
	{
		while (*p_big_first != *p_small && p_big_first-big < *big_size)//find first small in big
			++p_big_first;
		if(p_big_first-big < *big_size)
			return 0;
		else
			return -1;

	}


	while (p_big_next-big < *big_size)
	{
		while (*p_big_first != *p_small && p_big_first-big < *big_size-1)//find first small in big
			p_big_first++;

		p_big_next = p_big_first + 1;//set last in big to be thr next element

		p_small++;//next element in small

		while (*p_big_next != *p_small && p_big_next-big < *big_size)//find last small in big
			p_big_next++;

		if(p_big_next-big == *big_size)//if there is no next element of small in big
			return -1;

		skip = p_big_next - p_big_first-1;//set skip range

		//checking if small appears in the same skip
		if (*small_size>2)
			if(is_equal_next_skips(skip, big, big_size, small, small_size, p_big_next, p_big_next + 1))
				if(skip<minSkip)// if true, checking if minSkip is the smallest skip
					minSkip=skip;


		//continue to next members.
		p_big_first++;
		p_big_next = p_big_first+1;
	}
	if (minSkip==SIZE)// if not found any skip return -1
		return -1;
	else//else return minSkip
		return minSkip;


}

//initiate arrays with 0 for GCC
void array_init(int arr[],int maxsize=SIZE)
{
	for (int *p_arr = arr; p_arr - arr < maxsize; p_arr++)
	{
		*p_arr = 0;
	}
}

void insertion(int arr[],int maxsize=SIZE)//insert values to an array
{
	bool ok;// assumes input is correct
	do
	{
		ok = true;// assumes input is correct
		for (int *p_arr = arr; p_arr - arr < maxsize; p_arr++)// for every member of arr
		{
			cin >> *p_arr;// input to array member using its pointer
			if(*p_arr == 0)
				break;
		}
		for (int *p_arr = arr; p_arr - arr < maxsize && *p_arr!=0; p_arr++)// for every member of arr
		{
			if(*p_arr<0)// if input not correct
			{
				cout << "ERROR" << endl;
				ok=false;
			}
		}

	}while(!ok);

}

//main function.
int main(){

	int big[SIZE],small[SIZE],big_size,small_size;


	for ( int element:big)//initiate arrays with 0 for GCC
	{
		element = 0;
	}
	for ( int element:small)//initiate arrays with 0 for GCC
	{
		element = 0;
	}


	cout <<"Enter the size of big:"<<endl;// asking from user enter size for big
	cin >>big_size;

	cout <<"Enter "<< big_size <<" numbers:"<<endl;// asking from user enter numbers for big
	insertion(big,big_size);

	cout <<"Enter the size of small:"<<endl;// asking from user enter size for small
	cin>> small_size;

	cout <<"Enter "<< small_size <<" numbers:"<<endl;// asking from user enter numbers for small
	insertion(small,small_size);


	cout <<"Size of jump:"<<endl;
	cout<<minSkip(big,small,&big_size,&small_size)<<endl;


}
