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
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);

    int brr[n];
    for (int i = 0; i < n; i++)
        brr[i] = arr[n - i - 1];
    print(brr, n);

    return 0;
}
