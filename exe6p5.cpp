/*******************************************
Created by Maor Frost 206370231
introduction for cpm-sci - Meir Komar
exercise 6 task 5
getting two arrays from user and printing the symmetrical difference between them
********************************************/
#include <iostream>

using namespace std;

// calculating symmetrical difference between two arrays
void symmetricalDifference(int *set1, int *set2, int *difference, int &size)
{
    int k = 0;
    bool isIn;
    for (int i = 0; i < size; i++)
    {
        isIn = true;
        for (int j = 0; j < size; j++)
        {
            if (set1[i] == set2[j])
            {
                isIn = false;
            }
        }
        if (isIn)
        {
            difference[k] = set1[i];
            k++;
        }

    }
    size = k;
}

int main()
{
    const int SIZE = 6;

    int set1[SIZE];
    int set2[SIZE];
    int difference[SIZE];

    // getting values
    cout << "enter first 6 numbers:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> set1[i];
    }

    cout << "enter next 6 numbers:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> set2[i];
    }

    int k = SIZE; // we dont want to change SIZE so we makeing new var

    // calling the function
    symmetricalDifference(set1, set2, difference, k);

    cout << "set difference is:" << endl;

    // print the array
    for (int i = 0; i < k; i++)
    {
        cout << difference[i] << " ";
    }
    // if k = 0 print "empty"
    if (k == 0)
    {
        cout << "empty" << endl;
    }
    return 0;
}

/*****************************************************
enter first 6 numbers:
10 2 5 7 3 0
enter next 6 numbers:
1 2 8 9 10 11
set difference is:
10 2

Process exited with status 0
******************************************************/