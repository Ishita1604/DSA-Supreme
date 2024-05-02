#include <bits/stdc++.h>
using namespace std;

// 3) Debug the code. This code tries to implement Selection Sort.

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i]; // Changed j to i.
        arr[i] = temp;          // Changed j to i.
    }
}

int main()
{
    int arr[] = {9, 2, 6, 4, 5, 1, 0, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";

    return 0;
}