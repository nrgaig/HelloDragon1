/*
*  Created by Maor Frost 206370231 on 27.12.2021.
*  introduction for cpm-sci - Meir Komar
*	exercise 11 task 1
*  printing n times a,b
*/

#include <iostream>

using namespace std;

//printing n times a,b in recursion
void printABs(int n)
{

	if (n > 0)//while (n>1) print again recursively
	{
		cout << "a";//print "a"
		printABs(n - 1);//calling this function again
		cout << "b";//print "b"
	}

}//end printABs


int main()//main function
{
	int num;
	cout << "Enter a number:" << endl;//asking number from user
	cin >> num;
	printABs(num);//calling print function
	return 0;
}
/*
Enter a number:
5
aaaaabbbbb
 */