//Search, Sort and Merge Functions  Version 1 -WITHOUT RECURSIVE FUNCTIONS (see version2 for additional functions)
// Search: Sequential, Binary (iterative),
// Sort: Bubble, Insertion, Selection
// Merge: Iterative
// Written by Meir Komar
// Last Update - 12 Kislev 5776  - 24/11/15

#include <iostream>
using namespace std;

// the functions
int sequentialSearch(const int *arr, int n, int item);                          // the function returns the index of item or -1 if not found using sequential search
int binarySearch(const int *arr, int low, int high, int item);                  // the function returns the index of item or -1 if not found using binary search
void bubbleSort(int *arr, int n);                                               // bubble sort array of size n - in place- sorts the first n elements of arr in ascending order
void selectionSort(int *arr, int n);                                            // selection sort array of size n - in place - sorts the first n elements of arr in ascending order
void insertionSort(int *vec, int n);                                            // insertion sort array of size n - in place - sorts the first n elements of arr in ascending order
int *merge2SortedArrays(const int *arr1, int size1, const int *arr2, int size2);// merges 2 sorted arrays - of size1 and size2 WITH duplicates
// utility functions
void printArray(const int *arr, int size);// General function for printing an array of int with size elements
void swap(int *arr, int i, int j);


// Here are the Functions
void printArray(const int *arr, int size)// General function for printing an array of int with size elements
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}// end of printArray

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}// end of swap function

int sequentialSearch    // the function returns the index of item or -1 if not found using sequential search
        (const int *arr,// the array
         int n,         // the array size
         int item)      // what we are looking for
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
    }         // end of for
    return -1;// not found
}// end of sequential search

int binarySearch        // the function returns the index of item or -1 if not found using binary search
        (const int *arr,// the array
         int low,       // the lower boundary
         int high,      // the upper boundary
         int item)      // what we are looking for
{
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (item == arr[mid]) {
            return mid;
        }// found it
        else if (item > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }         // end while
    return -1;// not found
}// end of binary search

void bubbleSort(int *arr, int n)// improved bubble sort - sorts the first n elements of arr in ascending order
{
    bool flag = true;
    int i = 1;
    while (flag) {
        flag = false;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                flag = true;
            }
        }
        i++;
    }
}// end bubble sort

void selectionSort(int *arr, int n)// selection  sort - in place  - sorts the first n elements of arr in ascending order
{
    for (int i = 0; i < n - 1; i++) {
        int small = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[small]) {
                small = j;
            }
        }//  inner loop
        swap(arr, i, small);
    }//  outer loop
}// end of selectionSort

void insertionSort(int *arr, int n)// insertion sort - in place - sorts the first n elements of arr in ascending order
{
    int first, i;
    for (first = 1; first < n; first++) {
        int tmp = arr[first];
        for (i = first; i > 0 && tmp < arr[i - 1]; i--)
            arr[i] = arr[i - 1];
        arr[i] = tmp;
    }
}// end insertionSort


// Merging two sorted arrays to a third array. If the same element appears in both arrays
// it will appear TWICE in the new array
int *merge2SortedArrays(const int *arr1, int size1, const int *arr2, int size2) {
    int pArr1 = 0;// The current index of arr1
    int pArr2 = 0;// The current index of arr2
    int pArr3 = 0;// The current index of arr3
    int *arr3 = new int[size1 + size2];
    // Merge the items until the end of one  of the arrays
    while (pArr1 < size1 && pArr2 < size2) {
        if (arr1[pArr1] < arr2[pArr2]) {
            arr3[pArr3++] = arr1[pArr1++];
        } else {
            arr3[pArr3++] = arr2[pArr2++];
        }
    }

    // Copy the remainder of the first array
    while (pArr1 < size1) {
        arr3[pArr3++] = arr1[pArr1++];
    }
    // Copy the remainder of the second array
    while (pArr2 < size2) {
        arr3[pArr3++] = arr2[pArr2++];
    }
    return arr3;
}// end of merge2SortedArrays

int main() {
    int a[] = {5, 4, 3, 2, 1};
    insertionSort(a, 5);
    printArray(a, 5);

    return 0;
}
