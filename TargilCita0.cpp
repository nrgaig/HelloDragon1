//
// Created by Maor on 17.11.2021.
//

#include <iostream>

using namespace std;

void sumOfArr(int a[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += a[i];
    }
    cout << "The sum is: " << sum << ", The average is:" << (float) sum / len << endl;
}


void reverse(int a[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        int tmp = a[i];
        a[i] = a[len - i - 1];// very important as a tool for future reversing
        a[len - i - 1] = tmp;
    }
}

void artostanes()
{
    const int size = 100;
    bool array[size];
    int i, j;
    for (i = 0; i < size; i++)
    { array[i] = true; }
    cout << "The prime numbers between 1 and " <<
         size << " are:" << endl;
    for (i = 2; i < size; i++)
    {
        if (array[i])
        {
            cout << i << "  ";
            for (j = 2 * i; j < size; j += i)
            { array[j] = false; }
        }
    }
}

int main()
{

}