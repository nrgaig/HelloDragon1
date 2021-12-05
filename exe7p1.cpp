/* Created by Maor Frost 206370231
 * introduction for cpm-sci - Meir Komar
 *	exercise 7 task 1
 *  finding index of number in sorted array
 */

#include <iostream>

using namespace std;

// the function returns the index of item or -1 if not found using binary search
int binarySearch(int array[], const int SIZE, const int NUM)// sorted array, size of the arry, number we searching for.
{
    int low = 0, high = SIZE, mid;          // defining the lower & the upper boundaries

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (NUM == array[mid])
        {
            return mid;
        }       // found it
        else if (NUM > array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    } // end while
    return -1;       // not found
}

int main()
{
    int arr[10], numForSearch;//defining array
    bool isSorted = true;

    for (int i = 0; i < 10; i++)// reset the array
    {
        arr[i] = 0;
    }

    cout << "Enter 10 numbers:" << endl;//asking from user to enter numbers

    for (int i = 0; i < 10; i++)// inserting numbers to the array
    {
        cin >> arr[i];
        if ((i > 0 && arr[i] <= arr[i - 1]) ||
            arr[i] < 1)//if not leagal number (smaller than preveious or not positive)
        {
            //print error and restart the loop
            cout << "ERROR" << endl;
            isSorted = false;

        }

    }
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < 10; i++)// inserting numbers to the array
        {
            cin >> arr[i];
            if ((i > 0 && arr[i] <= arr[i - 1]) ||
                arr[i] < 1)//if not leagal number (smaller than preveious or not positive)
            {
                //print error and restart the loop
                cout << "ERROR" << endl;
                isSorted = false;

            }

        }
    }


    cout << "Enter 1 number:" << endl;//asking for number to search
    cin >> numForSearch;

    int index = binarySearch(arr, 10, numForSearch);// finding the index. if not found will be '-1'

    if (index == -1)// if index tells us it not found print "not found"
    {
        cout << "Not found" << endl;
    }
    else// else print the "found" message
    {
        cout << "The number " << numForSearch << " was found at index " << index << endl;
    }

}