/*******************************************
Created by Maor Frost 206370231
introduction for cpm-sci - Meir Komar
exercise 6 task 4
entering 6 float numbers and will output the indicies of the number
********************************************/
/*
targil: 6 sheela 4
lecturer: meir komer
discription: the program can sorted 6 numbers acording to the values from the smaller to the bigger.
**************************/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    float numbers [6]; // the first array (input by user)
    int i, small=0, size=6, place_1,place_2,place_3,place_4,place_5,place_6;

    cout <<"enter 6 numbers between 0 and 1:"<<endl;

    for ( i = 0; i < 6; i++)
    {
        cin>>numbers[i];
        if (numbers[i]<=0 || numbers[i]>=1) // to make sure: if the input iset is not between (0,1) the user have to put in the numbers from the beginning.
        {
            cout<<"ERROR"<<endl;
            i=-1;
        }
    }

    for (int k = 0; k < 6; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {

                if(numbers[i]<numbers[j]) //if the number smaller from the next one
                {
                    small+=1; // so count one, if the number is the smaller one so "small" value will be 5 becauze it is mean that the condition is true for all the numbers
                }

            }
            if (small==size-1) // in the next rotation size value is -1
            {
                if (size==6) // if the condition is true 5 times: (when size=6.the condition is 6-1 times
                {
                    place_1=i; // put this number un the first place
                }
                if (size==5) // if the condition is true only 4 times its mean: the number us smaller only from 4 numbers
                {
                    place_2=i; // put this number un the second place
                }
                if (size==4) // if the condition is true only 3 times its mean: the number us smaller only from 3 numbers
                {
                    place_3=i; // put this number in place_3
                }
                if (size==3) // if the condition is true only 2 times its mean: the number us smaller only from 2 numbers
                {
                    place_4=i; // put this number in place_4
                }
                if (size==2)
                {
                    place_5=i;
                }
                if (size==1)
                {
                    place_6=i;
                }
                size-=1;
            }

            small=0;
        }
    }

    int indices [6]={place_1,place_2,place_3,place_4,place_5,place_6}; // the new numbers array
    cout <<"sorted indices:"<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<indices[i]<<" ";
    }
    cout <<endl;

// system ("pause");
    return 0;
}
/***********OUTPUT***************

enter 6 numbers between 0 and 1:
0.3 0.56 0.4 0.215 0.0001 0.9
sorted indices:
4 3 0 2 1 5

*************************************************
enter 6 numbers between 0 and 1:
0.2 0.3 0.6 -2 0.2 0.5 0.4 0.7 0.9 0.25
ERROR
sorted indices:
0 5 2 1 3 4

**************************************************/