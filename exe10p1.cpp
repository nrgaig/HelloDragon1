/*  Created by Maor Frost 206370231 on 25/12/2021.
*   introduction for cpm-sci - Meir Komar
*	exercise 10 task 1
*   encrypting string in azby method end printing it
*/

#include <iostream>
#include<cstring>

using namespace std;

char* crypto(char* string1)
{
	for (int i = 0; i < strlen(string1); ++i)
	{
		if(string1[i]>96&&string1[i]<123)
			string1[i] =122-(string1[i]-97);
	}
	return string1;

}

//main function
int main()
{
	char string[80];

	cout <<"Enter a string:"<<endl;
	cin.getline(string,80);

	cout<<"After crypto:"<<endl
		<<crypto(string)<<endl;

	return 0;
}


