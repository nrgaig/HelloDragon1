/* Created by Maor Frost 206370231
 * introduction for cpm-sci - Meir Komar
 *	exercise 7 task
 *  gets 5 words into a matrix of 10 by 5 and sorts the words According the ABC
 */

#include <iostream>

using namespace std;

const int LENGTH = 10;
int const WIDTH = 5;

//enter only an 'a' to 'z'  to the matrix.
bool insertToMatrix(char arr[][WIDTH]);

void printMatrix(char arr[][WIDTH]);

void bubbleSort(char[][WIDTH]);

void swep(char[], char[]);

int main()// main function
{

    char Matrix[LENGTH][WIDTH];//declaring 2d matrix 10 by 5

    cout << "Enter 10 words:" << endl;//asking from user to enter words
    if (insertToMatrix(Matrix))       //inserting characters to the matrix
    {
        bubbleSort(Matrix);//sortrting the matrix
        cout << "After sorting:" << endl;
        printMatrix(Matrix);//printing the sorted matrix
    }

    return 0;
}

bool insertToMatrix(char arr[][WIDTH])//insert characters to the matrix
{

    bool ok = true;// assuming that the input is valid

    for (int i = 0; i < LENGTH; i++)
        for (int j = 0; j < WIDTH; j++)
            cin >> arr[i][j];

    for (int i = 0; i < LENGTH && ok; i++)
        for (int j = 0; j < WIDTH && ok; j++)
            if ('a' > arr[i][j] || arr[i][j] > 'z')
                ok = false;
    if (!ok)
        cout << "ERROR" << endl;
    return ok;//return the condition of input
}

void printMatrix(char arr[][WIDTH])//printing matrix
{
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++)
            cout << arr[i][j];//printing element
        cout << " ";
    }
}
void swep(char arr[][WIDTH], int num1, int num2)//swapping between two elements
{
    char temp[WIDTH];
    for (int i = 0; i < WIDTH; i++) {
        temp[i] = arr[num1][i];
        arr[num1][i] = arr[num2][i];
        arr[num2][i] = temp[i];
    }
}

void bubbleSort(char arr[][WIDTH])// improved bubble sort - sorts the first n elements of arr in ascending order
{
    bool swapped = true;//signing if element swaped
    int n = 0;
    while (swapped) {
        swapped = false;
        n++;
        for (int i = 0; i < LENGTH - n; i++) {
            int j = 0;
            while (arr[i][j] == arr[i + 1][j] && j < WIDTH)
                j++;
            if (arr[i][j] > arr[i + 1][j]) {
                swep(arr, i, i + 1);//swapping between elements
                swapped = true;
            }
        }
    }
}// end bubble sort
 /*

*/