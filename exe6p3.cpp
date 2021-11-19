/*******************************************
Created by Maor Frost 206370231
introduction for cpm-sci - Meir Komar
exercise 6 task 3
getting up to 10 numbers into array than remove duplicates
 printing the array and number of elements it contains
********************************************/
#include <iostream>

using namespace std;

//removeing duplicates and printin the rest and new size
void removeNumbers(int vector[100], int sizeV) {
    int count = 0;
    //hover the array and remove duplicates
    for (int i = 0; i < sizeV; i++) {
        for (int j = i + 1; j < sizeV; j++) {
            //if some value is duplicate erase it
            if (vector[i] == vector[j]) {
                vector[j] = 0;
            }
        }
    }

    //printing new array
    for (int i = 0; i < sizeV; i++) {
        //if the value not 0 means there is the element to print
        if (vector[i] != 0) {
            cout << vector[i] << " ";
            count++;//counting up number of elements
        }
    }
    //printing number of element
    cout << "\nnumber of elements: " << count << endl;
}

int main() {
    int vector[100], num;

    // enter valuse to array
    cout << "enter up to 100  values, to stop enter 0:" << endl;
    for (num = 0; num < 100; num++) {
        cin >> vector[num];
        // if input value is 0 stoping the loop
        if (vector[num] == 0) {
            break;
        }
    }

    cout << "the new vector is: " << endl;
    //removeing numbers and printin new array
    removeNumbers(vector, num);
}
/*****************************************************
enter up to 100  values, to stop enter 0:
1 2 8 9 5 4 1 2 3 5 1 4 8 9 6 5 
0
the new vector is: 
1 2 8 9 5 4 3 6 
number of elements: 8
Process exited with status 0
******************************************************/