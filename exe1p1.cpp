//Maor Frost 206370231
//מבוא למדעי המחשב - מאיר קומר
//	exercise 2 task 8
//	input of hour minute and seconds of takeoff and duration.
//printind landing time

#include<iostream>
using namespace std;

int main()
{
    int takeoffHH = 0,takeoffMM=0,takeoffSS=0,durationHH=0,durationMM=0,durationSS=0;
    //asking from the user to enter flight time values
    cout << "enter flight takeoff:"<<endl;
    //inserting values to variables
    cin >> takeoffHH>>takeoffMM>>takeoffSS;
    //asking from the user to enter duration values
    cout << "enter flight duration:"<<endl;
    //inserting values to variables
    cin >> durationHH>>durationMM>>durationSS;
    //print and calculating
    cout<< "flight arrival is:\n"
        << (takeoffHH+durationHH+(takeoffMM+durationMM+(takeoffSS + durationSS)/60)/60)%24<< ":" << (takeoffMM+durationMM+(takeoffSS + durationSS)/60)%60<< ":" <<(takeoffSS + durationSS)%60;


    return 0;
}
