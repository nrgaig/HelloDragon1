//  Created by Maor Frost 206370231 on 28.12.2021.
//  introduction for cpm-sci - Meir Komar
//  exercise 11 task 2
//  getting numbers from user into array
//  printing the smallest number assigned
//
#include <iostream>

using namespace std;

//getting array and size. returns index of smallest element in array
int smallest(int *arr, int size)
{
	if (size == 1)
	{//if subarray is only 1 member return 0
		return 0;
	}
	int min = smallest(arr + 1, size - 1);//initiate min as smallest index of subarray
	if (arr[0] < arr[min + 1])
	{//if first member is smaller than min member return 0
		return 0;
	}
	return min + 1;//if not smaller than min member return index
}

//main function
int main()
{
	int *arr;
	int num;
	do
	{
		cout << "Enter a number:" << endl;
		cin >> num;
		if (num <= 0)
		{
			cout << "ERROR" << endl;
		}
	}
	while (num <= 0);
	arr = new int[num];
	cout << "Enter array values: ";
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	cout << "The smallest is: " << arr[smallest(arr, num)] << endl;
	//delete[] arr;
	return 0;

}
/*
Enter a number:
2
Enter array values: 5 4
The smallest is: 4
 */