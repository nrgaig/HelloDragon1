/*  Created by Maor Frost 206370231 on 25/12/2021.
*   introduction for cpm-sci - Meir Komar
*	exercise 10 task 1
*   encrypting string in azby method and printing it
*/

#include <iostream>
#include<cstring>

using namespace std;

//encrypting string in azby method
char *crypto(char *string1)
{
	for (int i = 0; i < strlen(string1); ++i)//for each char in string do:
	{
		if (string1[i] > 96 && string1[i] < 123)
		{//if char is between a-z do
			string1[i] = 122 - (string1[i] - 97);
		}//abzy for this char
	}
	return string1;//return the string

}

//main function
int main()
{
	char string[81];//declaring string

	cout << "Enter a string:" << endl;//asking from user to enter a string
	cin.getline(string, 80);//get input

	cout << "After crypto:" << endl
	     << crypto(string) << endl;//printing encrypted string by calling crypto

	return 0;
}
/*
Enter a string:
Intr0duct10n t0 C0mputer Sc1ence
After crypto:
Imgi0wfxg10m g0 C0nkfgvi Sx1vmxv
*/