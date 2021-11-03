/* Created by Maor Frost 206370231
* introduction for cpm-sci - Meir Komar
*	exercise 5 task 2
*   getting number and printing all perfectnumbers below it & all 
*   perfecr number below 500
*/

#include <iostream>
using namespace std;

//checking if number is perfect
bool perfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if ((num % i) == 0) {
            sum += i;
        }
    }

    //returns bool value of if number equals to sum makes it perfect number
    return (num == sum);
}

//print all perfects below num
void printPerfects(int num) {
    for (int i = 1; i < num; i++) {
        if (perfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

//print all perfects below 500
void printPerfects() {
    for (int i = 1; i < 500; i++) {
        if (perfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

//main function
int main() {
    int num1;
    // asking for length and width
    cout << "Enter a number:" << endl;
    cin >> num1;

    //validating leagal number
    while (num1 <= 0) {
        cout << "ERROR" << endl;
        cin >> num1;
    }

    //printing all perfect below num1
    printPerfects(num1);
    //printing all perfect below 500
    printPerfects();

    return 0;
}

/*argv[0] = '/Users/maor/CLionProjects/HelloDragon1/cmake-build-debug/Hello1'
Enter a number:
7
6 
6 28 496 
Process exited with status 0
*/