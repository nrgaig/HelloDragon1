//  Created by Maor Frost 206370231 on 09/01/2022.
//  introduction for cpm-sci - Meir Komar
//  exercise 13 task 1
//  getting numbers from files and printing which file hase greater average
//
#include <iostream>
#include <fstream>
using namespace std;

//getting opened file. return average ofr file numbers
int fileAvg(ifstream &fin)//fin= "file input" as open file in input stream
{
	int sum = 0,count = 0,tmp;
	while(!fin.eof())//while file is not ended
	{
		fin>>tmp;//input number to tmp
		sum += tmp;//summarize tmp numbers
		count++;//counting numbers to average
	}
	return sum /count;//return average
}//end of fileAvg

//main function
int main()
{
	int avg1,avg2;
	ifstream fin1("grade1.txt");//declaring and open input file 1
	ifstream fin2("grade2.txt");//declaring and open input file 2

	if(!fin1||!fin2)//if file can't open
	{
		cout << "The file could not be opened" << endl;
		return -1;
	}

	avg1=fileAvg(fin1);//getting average of file1
	avg2=fileAvg(fin2);//getting average of file2


	cout << "highest average found in file ";
	//choosing between the files
	if(avg2<avg1)
		cout <<1<<endl;
	else
		cout<<2<<endl;

	//closing files
	fin1.close();
	fin2.close();
	return 0;
}
//==========grade1.txt==========
//98 5 9 80 6
//
//==========grade2.txt==========
// 99 98 97
//
//==========run sample==========
//highest average found in file 2
//