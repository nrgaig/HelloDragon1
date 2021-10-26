/* Created by Maor Frost 206370231
//  introduction for cpm-sci - Meir Komar
//	exercise 4 task 1
//	random ten numbers, print them, and print if they are sortted
*/

#include <iostream>

using namespace std;

int main() {
    int num, prev = (rand() % 1000) + 1;
    bool isSorted = true;

    //printing the first number
    cout << prev;
    //for 100 times
    for (int i = 1; i < 10; i++) {
        //generate random number
        num = (rand() % 1000) + 1;
        //printing random number
        cout << " " << num;
        //checking if previous number bigger than current for sorting
        if (num < prev) {
            isSorted = false;
        }
        prev = num;
    }

    if (isSorted) {
        cout << endl
             << "sorted list" << endl;
    } else {
        cout << endl
             << "not sorted list" << endl;
    }
}
//Users/maor/CLionProjects/HelloDragon1/cmake-build-debug/Hello1
//808 250 74 659 931 273 545 879 924 710
//not sorted list
//
//Process finished with exit code 0