#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    int i;
    cout << "\nENTIRE ARRAY:\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << "  ";
}

int main()
{
    cout << "-----\nSTART\n-----\n";

    int number[15]; // Only Declaration.
    cout << number; // Location of 1st element or, Base Address.

    // Garbage values --
    cout << "\nElement at Index 0: " << number[0];
    cout << "\nElement at Index 1: " << number[1];
    cout << "\nElement at Index 14: " << number[14];
    printArray(number, 15);

    number[14] = {1}; // One particular element gets Initialized.
    cout << "\n\nElement at Index 0: " << number[0];
    cout << "\nElement at Index 1: " << number[1];
    cout << "\nElement at Index 14: " << number[14];
    printArray(number, 15);

    int second[10] = {12, 3}; // Declaration & Initialization.
    // Only 1st and 2nd element get Initialized & Rest are 0 --
    cout << "\n\nElement at Index 0: " << second[0];
    cout << "\nElement at Index 1: " << second[1];
    cout << "\nElement at Index 9: " << second[9];
    printArray(second, 10);
    int secondSize = sizeof(second) / sizeof(second[0]);
    cout << "\nSize of Array: " << secondSize; // Not correct here!
    // As it gives size occupied by the entire array!
    // Solution: Explicitly pass the size.

    int third[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Declaration & Initialization.
    // Every element Statically Initialized --
    cout << "\n\nElement at Index 0: " << third[0];
    cout << "\nElement at Index 1: " << third[1];
    cout << "\nElement at Index 9: " << third[9];
    printArray(third, 10);
    int thirdSize = sizeof(third) / sizeof(third[0]);
    cout << "\nSize of Array: " << thirdSize; // Correct here

    int fourth[10] = {0}; // Declaration & Initialization.
    // Incase of 0, ALL get Initialized by 0 --
    cout << "\n\nElement at Index 0: " << fourth[0];
    cout << "\nElement at Index 1: " << fourth[1];
    cout << "\nElement at Index 9: " << fourth[9];
    printArray(fourth, 10);

    cout << "\n\nEverything is Fine!" << endl;
}
