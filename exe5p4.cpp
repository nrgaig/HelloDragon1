/* Created by Maor Frost 206370231
* introduction for cpm-sci - Meir Komar
*	exercise 5 task 4
*   calculating table size of Hash Table
*/

#include <iostream>
#include <cstdlib>

using namespace std;

//calculate if number is prime number
bool isPrime(int num) {
    for (int i = 2; i < num; ++i) {
        //if num divide by some number below return false
        if (num % i == 0)
            return false;
    }
    //otherwise return true
    return true;
}

//finding nearest prime number to given number
int findPrime(int num) {
    while (true) {
        //if num is prime number
        if (isPrime(num))
            return num;
        num++;
    }
}

//main function
int main() {
    int num1, size;
    // asking for length and width
    cout << "Enter number of values:" << endl;
    cin >> num1;

    //if user dont know table size and put Not positive number generate random number
    //else use user's input
    if (num1 <= 0) {
        srand((unsigned) time(NULL));
        cout << "Table size: " << findPrime((rand() % 100) + 10) << endl;
    } else {
        cout << "Table size: " << findPrime(num1) << endl;
    }

    return 0;
}

/*/Users/maor/CLionProjects/HelloDragon1/cmake-build-debug/Hello1
Enter number of values:
-5
Table size: 101

Process finished with exit code 0
*/