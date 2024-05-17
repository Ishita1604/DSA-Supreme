/**** Exponential / Doubling / Galloping / Struzik Search ****/

#include <bits/stdc++.h>
using namespace std;

// Exponential Search finds a subarray containing target, and only applies Binary Search on that, reducing some time complexity.
// Array must be sorted.
// Better for large / infinite / unbounded arrays.
// Better when x is present near beginning.

// Time: O(2^logM/2) or O(2^logM-1)
// Space: O(1)

int binarySearch(int arr[], int s, int e, int x)
{
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            s = mid + 1;
        else
            e = mid - 1;
        mid = (s + e) / 2;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0; // As we're initializing i from 1, so we check for index 0 separately.
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;                                     // Exponential increment.
    return binarySearch(arr, i / 2, min(i, n - 1), x); // So when i doubles up, it doesn't go out of bound!
}

int main()
{
    int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 56;
    int ans = exponentialSearch(arr, n, x);
    if (ans != -1)
        cout << "Element Found at Index: " << ans << endl;
    else
        cout << "Not Present!" << endl;

    return 0;
}