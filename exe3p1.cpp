/* Created by Maor Frost 206370231
//  introduction for cpm-sci - Meir Komar
//	exercise 3 task 5
//	getting numbers and print them from smallest to biggest
*/

#include <iostream>
using namespace std;

int main() {
  enum MONTHS {
    JAN = 31,
    FEB = 28,
    MAR = 31,
    APR = 30,
    MAY = 31,
    JUN = 30,
    JUL = 31,
    AUG = 31,
    SEP = 30,
    OCT = 31,
    NOV = 30,
    DEC = 31
  };
  int num1;
  cout << "enter a number: " << endl;
  cin >> num1;

  switch (num1) {
  case 1:
    cout << JAN << " days in the month" << endl;
    break;
  case 2:
    cout << FEB << " days in the month" << endl;
    break;
  case 3:
    cout << MAR << " days in the month" << endl;
    break;
  case 4:
    cout << APR << " days in the month" << endl;
    break;
  case 5:
    cout << MAY << " days in the month" << endl;
    break;
  case 6:
    cout << JUN << " days in the month" << endl;
    break;
  case 7:
    cout << JUL << " days in the month" << endl;
    break;
  case 8:
    cout << AUG << " days in the month" << endl;
    break;
  case 9:
    cout << SEP << " days in the month" << endl;
    break;
  case 10:
    cout << OCT << " days in the month" << endl;
    break;
  case 11:
    cout << NOV << " days in the month" << endl;
    break;
  case 12:
    cout << DEC << " days in the month" << endl;
    break;
  default: cout<<"there is no month."<<endl;
  }


  return 0;
}

// enter a number:
// 7
// 31 days in the month
//
// Process finished with exit code 0


