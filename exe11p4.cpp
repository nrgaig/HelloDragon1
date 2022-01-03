/*  Created by Maor Frost 206370231 on 03.01.2022
 *  introduction for cpm-sci - Meir Komar
 *	exercise 11 task 4
 *  getting value from user into array and reverse it and print it
 */

#include <iostream>

using namespace std;

void swap(int *arr, int i, int j)//swap between two members in array
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}// end of swap function

void reverse(int *arr, int size)//reverse member places in array recursively
{
	if (size > 1)//if size of array is more than one member
	{
		swap(arr, 0, size - 1);//swap between members
		reverse(arr + 1, size - 2);//continue to swap members recursively
	}
}//end of reverse

int main()//main function
{
	int *arr;//declaring array of integers
	int num;//num for input

	cout << "Enter a number: ";//asking number from user for size of array
	cin >> num;//input
	arr = new int[num];//creating array of integers with inserted size
	cout << "Enter array values: ";//asking numbers from user to insert to array
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}// input to array

	//printing array before reverse
	cout << "Before: \n";
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	reverse(arr, num);//reversing the array

	//printing array after reverse
	cout << "After: \n";
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//delete [] arr;
	return 0;
}//end of main

/* run sample:
 *
Enter a number: 7
Enter array values: 1 2 3 4 5 6 7
Before:
1 2 3 4 5 6 7
After:
7 6 5 4 3 2 1
 */
