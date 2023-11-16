#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
}

void initializeArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = 1;
    // Passing array as a parameter to a function.
    // It actually passes a pointer to the array's first index.
    // return arr;
}

int main()
{
    system("cls");
    int arr[100];
    int size = 10;
    initializeArr(arr, size);
    printArr(arr, size);

    return 0;
}
