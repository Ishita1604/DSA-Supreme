#include <bits/stdc++.h>
using namespace std;

// 1) Debug the code. This code is implementation for Binary Search.

int binarySearch(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x); // Added keyword `return`.
        else
            return binarySearch(arr, mid + 1, right, x); // Added keyword `return`.
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Not Found!";
    else
        cout << "Element Found at Index " << result << endl;
    return 0;
}