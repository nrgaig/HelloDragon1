// Maor Frost 206370231
// midtermTest.cpp : This file get number of row to build pyramid of numbers and printing the pyramid;
// com-sci intro - Meir Komar
//

#include <iostream>
using namespace std;

//getting line of numbers and printing pyramid in num of lines it get
void pyramid(int numOfLines)
{
	//for each line it prints:
	for (int line = 1; line <= numOfLines; line++)
	{
		//printng first '*' raw
		for (int j = 1; j < line; j++)
		{
			cout << '*';
		}
		//printing first half of pyramid
		for (int digit = 0; digit <= numOfLines-line; digit++)
		{
			cout << digit;
		}
		//printing second half of pyramid
		for (int digit = numOfLines - line; digit >= 0; digit--)
		{
			cout << digit;
		}

		//printing the last '*' row
		for (int j = 1; j < line; j++)
		{
			cout << '*';
		}

		//return to new line
		cout << endl;
	}
}

//main function -> start here
int main()
{
	int n;
	cin >> n;
	pyramid(n);
	return 0;
}

/**********Run Example***************
7
01234566543210
*012345543210*
**0123443210**
***01233210***
****012210****
*****0110*****
******00******

*************************************/