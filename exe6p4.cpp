/*******************************************
Created by Maor Frost 206370231
introduction for cpm-sci - Meir Komar
exercise 6 task 4
getting 6 floating numbers and printing te indices by sort from the smallest to the greatest
********************************************/
#include <iostream>

using namespace std;

// finding indices of the array and printing them
void findIndices(float *vector, int size)
{
    float smaller;
    int indices[size];//storing the indices
    int index;
    // running for every item in the array
    for (int i = 0; i < size + 1; i++)
    {
        index = 0;
        smaller = 1;
        // taking the smaller as 1 (that is the greater number possible in the array)
        for (int j = 0; j < size; j++)
        {
            // if the current element in array is smaller than "smaller"
            if (vector[j] < smaller)
            {
                smaller = vector[j];//the var smaller be the new smaller is vector[j]
                index = j;
            }
        }

        //making this index ve larger than other by assigning as 1
        vector[index] = 1;
        indices[i] = index;
    }

    // print the new array of indices using a for-range-loop
    for (int i: indices)
    {
        cout << i << " ";
    }
}

int main()
{
    const int SIZE = 6;
    float vector[SIZE];

    float temp;
    int i = 0;
    cout << "enter  6 numbers between 0 and 1:" << endl;
    // getting valid number
    while (i < 6)
    {
        cin >> temp;
        // validating input
        if (temp > 1 || temp < 0)
        {
            cout << "ERROR" << endl;
            //if its not correct input, reset the loop
            // if the user don't put 6 consecutive correct input the loop will never end
            i = 0;
        }
        else
        {
            // if the input is correct we put it in the i'th place in the vector (array)
            vector[i] = temp;
            i++;
        }
    }

    cout << "sorted indices:" << endl;
    // calling the function to find and print indices
    findIndices(vector, SIZE);
    return 0;
}

/*****************************************************
enter  6 numbers between 0 and 1:
0.9 0.05 0.002 0.1 0.14 0
sorted indices:
5 2 1 3 4 0
Process exited with status 0
******************************************************/