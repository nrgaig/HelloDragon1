//  Created by Maor Frost 206370231 on 09/01/2022.
//  introduction for cpm-sci - Meir Komar
//  exercise 13 task 2
//  getting characters from file anf counting each number in file
//  writing the counting into another file
//
#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;

//main function
int main()
{
	int index, counter[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char tav;
	char fileName[21];
	cin>>fileName;

	ifstream fin(fileName);

	if (!fin)///if file can't open - verifying the file is open
	{
		cout << "The file could not be opened" << endl;
		return -1;
	}

	while (!fin.eof())
	{
		tav = fin.get();
		if (tav > 47 && tav < 58)
		{
			index = ((int) tav) - 48;
			counter[index]++;
		}
	}
	fin.close();//closing the file

	ofstream fout("frequencyDigits.txt");//open file for writing
	if (!fout)///if file can't open - verifying the file is open
	{
		cout << "The file could not be opened" << endl;
		return -2;
	}

	//writing into the file
	cout<<"digit\tfrequency"<<endl;
	fout<<"digit\tfrequency"<<endl;
	for (int i = 0; i < 10; i++)//writing numbers and their frequency
	{
		cout << i << "\t\t" << counter[i] << endl;
		fout << i << "\t\t" << counter[i] << endl;
	}
	fout.close();//close file for writing into ROM

	return 0;
}

//************* run sample ***************
//digit	frequency
//0		2
//1		4
//2		2
//3		2
//4		5
//5		4
//6		4
//7		1
//8		1
//9		4
//
//=========== information.txt ============
//asd12dd498645102495asf61934560143yr9756
//
//========= frequencyDigits.txt ==========
//digit	frequency
//0		2
//1		4
//2		2
//3		2
//4		5
//5		4
//6		4
//7		1
//8		1
//9		4
//

//Thanks for reviewing my programs through the semester.
// I hope it was clear and good algorithms.
// Good Luck in the tests...
// See you on next semester :) Maor.