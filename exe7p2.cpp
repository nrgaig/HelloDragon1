/* Created by Maor Frost 206370231
 * introduction for cpm-sci - Meir Komar
 *	exercise 7 task 2
 *  take 3 arrays from user and merge them into one
 */

#include <iostream>

void printArray(int *pArr, int size);

using namespace std;

int insertion(int arr[])// inserting values to array
{
    int size = 0;//defining the size of array
    bool isNotSorted = false;// assuming array will be sorted

    for (int i = 0; i < 10; i++)// inserting numbers to the array
    {
        cin >> arr[i];//getting number
        if (arr[i] == 0)
        {// stop getting numbers if 0 entered
            break;
        }
        size++;

        //if not legal number (greater than previous or not positive)
        if ((i > 0 && arr[i] >= arr[i - 1]) || arr[i] < 1)
        {
            isNotSorted = true; //defining the array not sorted
        }

    }
    while (isNotSorted)// if not sorted reinsert values
    {
        cout << "ERROR" << endl;
        size = 0;//reset the sizeof array
        isNotSorted = false;// assuming array will be sorted
        for (int i = 0; i < 10; i++)// inserting numbers to the array
        {
            cin >> arr[i];//getting number
            if (arr[i] == 0)
            {// stop getting numbers if 0 entered
                break;
            }
            size++;

            //if not legal number (equal or greater than previous or not positive)
            if ((i > 0 && arr[i] >= arr[i - 1]) || arr[i] < 1)
            {
                isNotSorted = true; //defining the array not sorted
            }
        }
    }
    return size;//return the size of the array
}

// Merging two sorted arrays to a third array. If the same element appears in both arrays
// it will appear TWICE in the new array
int *merge2SortedArrays(const int *arr1, int size1, const int *arr2, int size2)
{
    int pArr1 = 0;// The current index of arr1
    int pArr2 = 0;// The current index of arr2
    int pArr3 = 0;// The current index of arr3
    int *arr3 = new int[size1 + size2];
    // Merge the items until the end of one  of the arrays
    while (pArr1 < size1 && pArr2 < size2)
    {
        if (arr1[pArr1] > arr2[pArr2])
        {
            arr3[pArr3++] = arr1[pArr1++];
        }
        else
        {
            arr3[pArr3++] = arr2[pArr2++];
        }
    }

    // Copy the remainder of the first array
    while (pArr1 < size1)
    {
        arr3[pArr3++] = arr1[pArr1++];
    }
    // Copy the remainder of the second array
    while (pArr2 < size2)
    {
        arr3[pArr3++] = arr2[pArr2++];
    }
    return arr3;
}// end of merge2SortedArrays

//main function
int main()
{
    int vector1[10], vector2[10], vector3[10];//defining 3 arrays

    cout << "Enter values for the first vector:" << endl;//asking from user to enter numbers for first array

    int size1 = insertion(vector1);// inserting numbers to the array

    cout << "Enter values for the second vector:" << endl;//asking from user to enter numbers for second array

    int size2 = insertion(vector2);// inserting numbers to the array

    cout << "Enter values for the third vector:" << endl;//asking from user to enter numbers for third array

    int size3 = insertion(vector3);// inserting numbers to the array

    //merging into temp array
    int *tempVector = merge2SortedArrays(vector1, size1, vector2, size2);

    //merging into final array
    int *finalMerge = merge2SortedArrays(tempVector, size1 + size2, vector3, size3);

    cout << "Merged vector is:"<<endl;
    printArray(finalMerge, size1 + size2 + size3);

}

void printArray(int *pArr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << pArr[i] << " ";
    }
}

