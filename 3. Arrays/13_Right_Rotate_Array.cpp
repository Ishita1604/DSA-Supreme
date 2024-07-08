#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    int arr[] = {4, 6, 1, 3, 42, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);

    int no_of_rotations;
    cout << "Enter the Number of Rotations: ";
    cin >> no_of_rotations;

    for (int i = 0; i < no_of_rotations; i++)
    {
        int rightmost_element = arr[n - 1];
        for (int j = n - 2; j >= 0; j--)
            arr[j + 1] = arr[j];

        arr[0] = rightmost_element;
        cout << "After Right Rotating ... (" << i + 1 << ")" << endl;
        print(arr, n);
    }

    return 0;
}