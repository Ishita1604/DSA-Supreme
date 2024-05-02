#include <bits/stdc++.h>
using namespace std;

// 4) Debug the code. This code tries to implement Bubble Sort.

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // Changed (n - 2) to n - 1.
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {9, 2, 6, 4, 5, 1, 0, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";

    return 0;
}