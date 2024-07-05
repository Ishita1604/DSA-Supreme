// This code shows that when an array is passed as argument, it is passed as reference.

#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

void inc(int arr[]) // Or, void inc(int *arr), both are same.
{
    // An array passed to a function is always treated as a pointer to its base element.
    // Changes inside function treated as changes in actual array.
    // Array as a whole can't be passed to a function.
    arr[0] = arr[0] + 10;
    print(arr, 5);
}

void printOther(int x)
{
    cout << x << endl;
}

void incOther(int x)
{
    x++;
    printOther(x); // Value inside function.
    // The value is incremented in copy of x created due to this function.
    // And not in actual memory block.
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    print(arr, 5);
    // Call by reference.
    inc(arr);
    print(arr, 5); // Value of actual array has changed.

    cout << "\n\n\n";
    // Call by value.
    int x = 69;
    printOther(x);
    incOther(x);   // Gets incremented in function only.
    printOther(x); // Remains the same.

    return 0;
}
