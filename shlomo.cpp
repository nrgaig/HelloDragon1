//
// Created by Maor on 12.10.2021.
//
#include <cstdio>
#include<iostream>
using namespace std;

int main()
{
    int b,c;
    int a=b=c=0;
    cout << a <<b << c ;
    int choose1=0;
    cout <<" if your name is shlomo press 1"<< endl;
    cin >> choose1;

    if(choose1==1){
        cout<< "tinok tinok!!\nGO AWAY!!"<< endl;
        return 0;
    }

    else{
        cout<< "gever gever!!"<<endl;
    }

    cout<< "tnx for using my program :)"<<endl;
    return 0;
}