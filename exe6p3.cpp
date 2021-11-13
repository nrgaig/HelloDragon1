/*******************************************
Created by Maor Frost 206370231
introduction for cpm-sci - Meir Komar
exercise 6 task 3

********************************************/
#include<iostream>

using namespace std;


void removeNumber(int *rVector[100], int indx)
{
    int i=0;
    for (; i < 100 && rVector[i] != 0; i++)
    {
       
    }

}

int main()
{
    int vector[100], num;

    cout << "enter up to 100  values, to stop enter 0:" << endl;
    for (int i = 0; i < 100||num!=0; i++)
    {
        cin >> num;
        vector[i] = num;
        

    }

    for (int i = 0; i < 100 || vector[i]!=0; i++)
    {
        for (int j = i+1; j < 100 || vector[j] != 0; j++)
        {
            if (vector[i] == vector[j])
                removeNumber(&vector, i);
        }

    }
        


}