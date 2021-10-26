/* Created by Maor Frost 206370231
* introduction for cpm-sci - Meir Komar
*	exercise 4 task 4
*
*/

#include <iostream>

using namespace std;

int main() {
    float x;
    int n;
    //geting leagal numbers
    cout << "enter 2 numbers:" << endl;

    cin >> x;

    cin >> n;
    while (n <= 0) {
        cout << "ERROR" << endl;
        cin >> n;
    }

    // an = (-1)^n-1 / (2n-1) * x^(2n-1);
    //       counter / base   * multiplier(aka multi)
    float count = 1, multi = x, sum = 0;

    //multipling counter
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            count *= (-1);
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            multi *= x;
            cout << "multi" << multi << endl;
        }
        sum += ((count / ((2.0 * i) - 1)) * multi);
        count = 1;
        multi = x;
    }

    cout << sum << endl;
}

/*ed with status 0*/