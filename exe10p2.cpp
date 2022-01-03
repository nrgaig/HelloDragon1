/*  Created by Maor Frost 206370231 on 25/12/2021.
*   introduction for cpm-sci - Meir Komar
*	exercise 10 task 2
*   reversing each word in the string by itself
*/

#include <iostream>
#include<cstring>

using namespace std;

//reversing each word in the string
char *reverse(char *str)
{

	int word_start = 0;

	for (int i = 0; i <= strlen(str); i++)//running on thr string
	{
		if (str[i] == ' ' || str[i] == '\0')//if char is a space
		{
			char *temp = new char[i - word_start];//creating temp string

			for (int j = i - 1; j > word_start - 1; --j)//running on the word backwards
			{
				temp[i - j - 1] = str[j];//entering word to temp backwards
			}
			for (int j = 0; j < i - word_start; ++j)//copping the word backwards
			{
				str[word_start + j] = temp[j];
			}
			word_start = i + 1;//setting word_start to next word

			delete[] temp;//delete temp
		}
	}
	return str;
}

//main function
int main()
{
	char str[81];

	cout << "Enter a string:" << endl;//asking from user to enter a string
	cin.getline(str, 80);
	cout << "After reverse: ";
	puts(reverse(str));//printing str reversed

	return 0;
}
/*
Enter a string:
no you smarty666 enter 345 strings
After reverse: on uoy 666ytrams retne 543 sgnirts

Process finished with exit code 0
 */