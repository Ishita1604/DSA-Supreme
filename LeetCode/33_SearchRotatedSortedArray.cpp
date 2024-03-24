/**** LeetCode 33: Binary Search in Rotated & Sorted Array ****/

// Time: O(log n)
// 1. [File: DSA-Supreme/5. Searching Sorting/14_PivotElement.cpp] to find the pivot element.
// 2. Compare target to understand in which array it is in.
// 3. Perform binary search in that array.


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


int binarySearch(vector<int> arr, int s, int e, int target)
{
    int mid = s + ((e - s) / 2);
    while (s <= e)
    {
        if (target == arr[mid])
            return mid;
        else if (target > arr[mid]) // Search in right.
            s = mid + 1;
        else // Search in left.
            e = mid - 1;
        mid = s + ((e - s) / 2);
    }
    return -1;
}

int search(vector<int> &arr, int target)
{
    int ans = 0;
    int pivotIndex = pivot(arr);

    if (pivotIndex == -1) // If pivotIndex is -1, the array is not rotated.
        return binarySearch(arr, 0, arr.size() - 1, target);

    if (target >= arr[0] && target <= arr[pivotIndex]) // Binary search in Line A:
        ans = binarySearch(arr, 0, pivotIndex, target);

    else // Binary search in Line B:
        ans = binarySearch(arr, pivotIndex + 1, arr.size() - 1, target);

    return ans;
}

int main()
{
    vector<int> arr = {9, 10, 2, 4, 6, 8};
    int target = 8;
    int targetIndex = search(arr, target);
    if (targetIndex == -1)
        cout << "Target Not Found!" << endl;
    else
        cout << "Target Fount at Index: " << targetIndex << endl;

    return 0;
}
