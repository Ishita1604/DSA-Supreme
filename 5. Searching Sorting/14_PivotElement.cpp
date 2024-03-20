/*** Find Pivot Element in an Array ***/

// Array is sorted & rotated.
// No duplicate elements.
// Pivot divides array into 2 increasing arrays, Line A and Line B.
// Time: O(log n)

#include <bits/stdc++.h>
using namespace std;


int pivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e) // Only single element in array.
            return s;
        if ((mid + 1 <= e) && arr[mid] > arr[mid + 1]) // To ensure (mid + 1) doesn't get out of array.
            return mid;
        if ((mid - 1 >= s) && arr[mid - 1] > arr[mid]) // To ensure (mid - 1) doesn't get out of array.
            return mid - 1;
        if (arr[s] > arr[mid])
            e = mid - 1; // We are on Line B so further search in left.
        else
            s = mid + 1; // We are on Line A so further search in right.
        mid = s + (e - s) / 2;
    }

    return -1;
}


int main()
{
    vector<int> arr = {9, 10, 2, 4, 6, 8};
    int ans = pivot(arr);
    cout << "Pivot Element: " << arr[ans] << endl;
    cout << "Index: " << ans << endl;

    return 0;
}