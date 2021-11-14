/*******************************************
Created by Maor Frost 206370231
introduction for cpm-sci - Meir Komar
exercise 6 task 2

********************************************/
#include <iostream>

using namespace std;

int main()
{

    int vector1[500], vector2[100], size1, size2, count = 0;

    //entering sze and values for first vector array
    cout << "enter size of first array:" << endl;
    cin >> size1;
    cout << "enter first array values:" << endl;
    for (int i = 0; i < size1; ++i)
    {
        cin >> vector1[i];
    }

//entering sze and values for second vector array
    cout << "enter size of second array:" << endl;
    cin >> size2;
    cout << "enter second array values:" << endl;
    for (int i = 0; i < size2; ++i)
    {
        cin >> vector2[i];
    }

    //entering first array to check if some
    for (int i = 0; i < size1; ++i)
    {
        //if i value in vector1 match first value in vector2
        if (vector2[0] == vector1[i])
        {
            //counting up this appearance
            count++;
            // checking if all values match in this appearance
            for (int j = 0; j < size2; ++j)
            {
                // if some value in the first array not match the value in second array
                if (vector1[i + j] != vector2[j])
                {
                    // return the counting and break the loop
                    count--;
                    break;
                }
            }
        }
    }

    //printing the result
    cout << "result: " << count << " times" << endl;
}