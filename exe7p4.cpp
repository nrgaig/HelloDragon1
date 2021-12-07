/* Created by Maor Frost 206370231
 * introduction for cpm-sci - Meir Komar
 *	exercise 7 task
 *  gets 5 words into a matrix of 10 by 5 and sorts the words According the ABC
 */

#include <iostream>

using namespace std;

const int LENGTH = 10;
const int WIDTH = 5;


//enter only an 'a' to 'z'  to the matrix.
bool insertToMatrix(char arr[][WIDTH])//insert characters to the matrix
{
    bool valid = true;// assuming that the input is valid

    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < LENGTH && valid; i++) {
        for (int j = 0; j < WIDTH && valid; j++) {
            if ('a' > arr[i][j] || arr[i][j] > 'z') {
                valid = false;
            }
        }
    }
    if (!valid) {
        cout << "ERROR" << endl;
    }
    return valid;//return the condition of input
}

void swapping(char arr[][WIDTH], int num1, int num2)//swapping between two elements
{
    char temp[WIDTH];
    for (int i = 0; i < WIDTH; i++) {
        temp[i] = arr[num1][i];
        arr[num1][i] = arr[num2][i];
        arr[num2][i] = temp[i];
    }
}
void charBubbleSort(char arr[][WIDTH])// improved bubble sort - sorts the first n elements of arr in ascending order
{
    bool flag = true;//flag for signing if element swaped
    int n = 0;
    while (flag) {
        flag = false;
        for (int i = 0; i < LENGTH - n; i++) {
            int j = 0;
            while (arr[i][j] == arr[i - 1][j] && j < WIDTH)//forward to next letter in the string
            {
                j++;
            }

            if (arr[i][j] > arr[i + 1][j]) {
                swapping(arr, i, i + 1);//swapping between elements
                flag = true;
            }
        }
        n++;
    }
}// end bubble sort


void printMatrix(char arr[][WIDTH])//printing matrix
{
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << arr[i][j];
        }//printing element
        cout << " ";
    }
}

int main()// main function
{
    char words[LENGTH][WIDTH];//declaring 2d matrix 10 by 5

    cout << "Enter 10 words:" << endl;//asking from user to enter words
    if (insertToMatrix(words))        //inserting characters to the matrix
    {
        charBubbleSort(words);//sortrting the matrix
        cout << "After sorting:" << endl;
        printMatrix(words);//printing the sorted matrix
    }

    return 0;
}