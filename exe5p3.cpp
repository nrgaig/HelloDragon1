/* Created by Maor Frost 206370231
* introduction for cpm-sci - Meir Komar
*	exercise 5 task 3
*   getting firs 8 digit of id and printing full id number
*/

#include <iostream>

using namespace std;

//calculates sum of number's digits
int sumDigits(int num) {
    int sum = 0;
    //summarize all digits
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    //return sum of all digits
    return sum;
}

//taking start id and calculate last digit number
int lastDigitId(int idStart) {
    int sum = 0;
    //calculating sum of all numbers
    for (int i = 8; i > 0; i--, idStart /= 10) {
        sum += sumDigits((idStart % 10) * (2 - (i % 2)));
    }

    //return 10 minus last digit of sum as last digit of id
    return (10 - (sum % 10));
}

//main function
int main() {
    int num1;

    // asking for start of id
    cout << "Enter your ID:" << endl;
    cin >> num1;

    //validating legal number
    while (num1 <= 0) {
        cout << "ERROR" << endl;
        cin >> num1;
    }

    //printing your full id
    cout << "Your full ID is:" << endl
         << num1 << lastDigitId(num1) << endl;


    return 0;
}

/*/Users/maor/CLionProjects/HelloDragon1/cmake-build-debug/Hello1
Enter your ID:
72857354
Your full ID is:
728573544

Process finished with exit code 0
 */