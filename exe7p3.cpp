/* Created by Maor Frost 206370231
 * introduction for cpm-sci - Meir Komar
 *	exercise 7 task 2
 *  get 10x10 matrix and sort top triangle and bottom triangle
 */

#include <iostream>

using namespace std;

void insertionSort(int *arr, int n)// in place - sorts the first n elements of arr in not descending order
{
	int first, i;
	for (first = 1; first < n; first++)
	{
		int tmp = arr[first];
		for (i = first; i > 0 && tmp <= arr[i - 1]; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[i] = tmp;
	}
}// end insertionSort

void printMatrix(int arr[][10])// printing 10x10 matrix
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()//main function
{
	int matrix[10][10];//declaring 2d matrix 10 by 10

	//insert 100 numbers from user to matrix
	cout << "Enter the values:" << endl;
	for (auto &i: matrix)
	{
		for (int &j: i)
		{
			cin >> j;
		}
	}

	//print 10x10 matrix
	cout << "Before sorted:" << endl;
	printMatrix(matrix);

	//declaring temp array and its index
	int tempArr[45], pTemp = 0;

	//inserting top half to new array
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 1 + i; j < 10; ++j)
		{
			tempArr[pTemp] = matrix[i][j];
			pTemp++;
		}
	}

	insertionSort(tempArr, 45);//insertion sort for top half
	pTemp = 0;
	for (int i = 0; i < 9; ++i)//insert back to matrix
	{
		for (int j = 1 + i; j < 10; ++j)
		{
			matrix[i][j] = tempArr[pTemp];
			pTemp++;
		}
	}

	//inserting bottom half to new array
	pTemp = 0;
	for (int i = 1; i < 10; ++i)//insert back to matrix
	{
		for (int j = 0; j < i; ++j)
		{
			tempArr[pTemp] = matrix[i][j];
			pTemp++;
		}
	}

	insertionSort(tempArr, 45);//insertion sort for bottom half
	pTemp = 0;
	for (int i = 1; i < 10; ++i)//insert back to matrix
	{
		for (int j = 0; j < i; ++j)
		{
			matrix[i][j] = tempArr[pTemp];
			pTemp++;
		}
	}

	//printing sorted matrix
	cout << "Sorted matrix:" << endl;
	printMatrix(matrix);

}
/*********************
 * Enter the values:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 13 23 63 64 65 66 71 72 73
4 14 24 34 74 75 76 77 81 82
5 15 25 35 45 83 84 85 86 87
6 16 26 36 46 56 88 91 92 93
7 17 27 37 47 57 67 94 95 96
8 18 28 38 48 58 68 78 97 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100
Before sorted:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 13 23 63 64 65 66 71 72 73
4 14 24 34 74 75 76 77 81 82
5 15 25 35 45 83 84 85 86 87
6 16 26 36 46 56 88 91 92 93
7 17 27 37 47 57 67 94 95 96
8 18 28 38 48 58 68 78 97 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100

Sorted matrix:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 4 23 63 64 65 66 71 72 73
5 6 7 34 74 75 76 77 81 82
8 9 10 13 45 83 84 85 86 87
14 15 16 17 18 56 88 91 92 93
19 20 24 25 26 27 67 94 95 96
28 29 30 35 36 37 38 78 97 98
39 40 46 47 48 49 50 57 89 99
58 59 60 68 69 70 79 80 90 100

 * */