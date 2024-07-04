#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void updateArray(int a[], int n, int el, int index)
{
    if (index > 0 && index < n)
        a[index] = el;
    else
        cout << "\nIndex Out Of Range!" << endl;
}

int main()
{
    int size;
    cout << "Enter Array Size: ";
    cin >> size;
    int arr[100];
    cout << "\nEnter the Elements --" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\nPrinting The Array --" << endl;
    printArray(arr, size);

    int el, index;
    cout << "\nEnter New Element & Index: ";
    cin >> el >> index;

    updateArray(arr, size, el, index);
    printArray(arr, size);

    return 0;
}
