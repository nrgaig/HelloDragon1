// Created by Maor Frost 206370231
//  introduction for cpm-sci - Meir Komar
//	exercise 3 task 4
//	getting numbers and tells if they can make triangle
//

#include<iostream>

using namespace std;

int main() {
    int side1, side2, side3;
    char char1;

    cout << "enter 3 numbers:" << endl;
    cin >> side1>>side2>> side3;

    //checking sizes
    if (side1==side2 && side2==side3)
    {
        cout<< "equilateral triangle" <<endl;
    } else if (side1==side2 || side2==side3 || side1==side3)
    {
        cout<< "isosceles triangle" << endl;
    } else if (side1+side2 > side3 && side2+side3 > side1 && side1+side3 > side2)
    {
        cout << "scalene triangle" << endl;
    } else cout<< "cannot form a triangle" <<endl;



}
//Users/maor/CLionProjects/HelloDragon1/cmake-build-debug/Hello1
//enter 3 numbers:
//3 4 5
//scalene triangle
//
//Process finished with exit code 0
