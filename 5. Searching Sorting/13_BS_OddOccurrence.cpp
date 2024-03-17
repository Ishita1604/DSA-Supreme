/**** Find Odd Occurring Element in Array ****/

// Answer occurs at even index.
// All elements in pairs except answer.
// Pairs are not adjacent i.e. there can't be more than 2 consecutive occurrence of an element.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (s == e) // Single element.
            return s;
        if (mid % 2 == 0) // Even index.
        {
            // Compare with next element.
            if (arr[mid] == arr[mid + 1])
                // Search in right.
                s = mid + 2; // As (mid + 1) already compared.

            else // (arr[mid] != arr[mid + 1])
                // Search in left.
                e = mid; // As mid can be answer.
        }
        else // Odd index.
        {
            // Compare with previous element.
            if (arr[mid] == arr[mid - 1])
                // Search in right.
                s = mid + 1;

            else
                // Search in left.
                e = mid - 1;
        }
        mid = (s + e) / 2;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7};
    int ans = solve(arr);
    cout << "Odd Occuring Element is: " << arr[ans] << endl;

    return 0;
}