/****    Binary Search in Nearly Sorted Array    ****/
// The index `i` of a sorted array can be placed at positions:
// (i - 1), i or (i + 1) in a nearly sorted array.

#include <bits/stdc++.h>
using namespace std;


int binarySearchNearlySortedArray(vector<int> arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
            return mid;
        if ((mid - 1) >= 0 && arr[mid - 1] == target)
            return (mid - 1);
        if ((mid + 1) < n && arr[mid + 1] == target)
            return (mid + 1);
        else if (arr[mid] > target)
            e = mid - 2;
        else
            s = mid + 2;
        mid = s + (e - s) / 2;
    }
    return -1;
}


int main()
{
    // Nearly sorted array for {3, 10, 20, 40, 50, 70, 80}:
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int target = 80;
    int index = binarySearchNearlySortedArray(arr, target);
    if (index == -1)
        cout << "Target Not Found!" << endl;
    else
        cout << "Target Found at Index: " << index << endl;

    return 0;
}