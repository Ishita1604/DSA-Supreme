#include <bits/stdc++.h>
using namespace std;

// 2) Debug the code.
// This code is implementation for Binary Search for calculating ceil index.
// The ceil index is the index of the smallest element in the array that is greater than or equal to a given target value.
// Means from all elements greater than target, find the smallest one!

int ceilIndex(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            ceil = mid + 1; // Added these.
            return ceil;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
        {
            // ceil = mid;
            right = mid - 1;
        }
    }
    return ceil;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int result = ceilIndex(arr, n, x);
    cout << "Ceil Index: " << result << endl;
    return 0;
}