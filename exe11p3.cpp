/*  Created by Maor Frost 206370231 on 03.01.2022
 *  introduction for cpm-sci - Meir Komar
 *	exercise 11 task 3
 *
 */

#include <iostream>

using namespace std;

int smallest(int*, int);//return the index of smallest value

void sort(int*, int);//selection sort

//main function
int main()
{
	int* arr;//declaring array of integers
	int num;//num for input
	do {
		cout << "Enter a number:" << endl;//asking from user
		cin >> num;
		if (num <= 0)
			cout << "ERROR" << endl;
	} while (num <= 0);
	arr = new int[num];//declaring array of integers with sizeof num
	cout << "Enter array values: ";//asking for values to array
	for (int i = 0; i < num; i++)
		cin >> arr[i];//inserting form input
	cout << "Before: \n";
	for (int i = 0; i < num; i++)//printing values before sorting
		cout << arr[i] << " ";
	cout << endl;
	sort(arr, num);
	cout << "After: \n";
	for (int i = 0; i < num; i++)//printing values after sorting
		cout << arr[i] << " ";
	cout << endl;
	//delete [] arr;
	return 0;
}//end of main

//getting array and size. returns index of smallest element in array
int smallest(int *arr, int size)
{
	if (size == 1)//if subarray is only 1 member return 0
	{
		return 0;
	}
	int min = smallest(arr + 1, size - 1);//initiate min as smallest index of subarray

	if (arr[0] < arr[min + 1])//if first member is smaller than min member return 0
	{
		return 0;
	}
	return min + 1;//if not smaller than min member return index
}//end of smallest

//recursive selection sort - sorts the first n elements of arr in ascending order
void sort(int *arr, int n)
{
	if (n>1)//if size of array is more than one
	{
		int smallIndex = smallest(arr, n);//getting smallest index of smallest value

		// swap(arr,0,smallIndex);
		int temp = arr[0];
		arr[0] = arr[smallIndex];
		arr[smallIndex] = temp;

		sort(arr + 1, n - 1);//continue sorting arr recursively
	}
}//end of sort


