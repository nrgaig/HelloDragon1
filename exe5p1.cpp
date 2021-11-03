/* Created by Maor Frost 206370231
* introduction for cpm-sci - Meir Komar
*	exercise 5 task 1
*   geting numbers of length,width of triangle and radius of circle and print their area.
*/

#include <iostream>
using namespace std;

//calculates area of rectangle
int area(int length, int width) {
    return length * width;
}

// calculates area of circle
float area(int radius) {
    const float PI = 3.14159;
    return PI * radius * radius;
}
//main function
int main() {
    int num1, num2, num3;
    // asking for length and width
    cout << "Enter length and width of the rectangle:" << endl;
    cin >> num1;

    //validating leagal number
    while (num1 <= 0) {
        cout << "ERROR" << endl;
        cin >> num1;
    }
    cin >> num2;
    while (num2 <= 0) {
        cout << "ERROR" << endl;
        cin >> num2;
    }

    //printing area of rectangle
    cout << area(num1, num2) << endl;

    //asking for radius
    cout << "Enter radius of the circle:" << endl;
    cin >> num1;

    //validating leagal number
    while (num1 <= 0) {
        cout << "ERROR" << endl;
        cin >> num1;
    }

    //printing area of circle
    cout << area(num1) << endl;

    return 0;
}

/*argv[0] = '/Users/maor/CLionProjects/HelloDragon1/cmake-build-debug/Hello1'
Enter length and width of the rectangle:
15
2
30
Enter radius of the circle:
7
153.938
Process exited with status 0
*/