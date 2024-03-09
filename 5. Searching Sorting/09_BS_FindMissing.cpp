// Array has elements from 1 to N in SORTED ORDER!
// Where (N-1) is size of array.
// But there is one missing.
// Find that missing element!

#include <bits/stdc++.h>
using namespace std;

// Algorithm:
// As array is sorted, when there is a missing element, then element & index difference becomes = 2.
// Before missing element, difference is = 1.
// So this is our logic.
// If difference is == 1, keep searching right.
// When difference == 2, store that index and search further left.


// TIME: O(log n)
// SPACE: O(1)
int missingElement(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int m = s + ((e - s) / 2);
    int ans = -1;

    while (s <= e)
    {
        // Difference is == 1, keep searching right.
        if (arr[m] - m == 1)
            s = m + 1;

        else if (arr[m] - m == 2)
        {
            // Difference is == 2, store and search left.
            ans = m;
            e = m - 1;
        }
        m = s + ((e - s) / 2);
    }
    // If the last element is missing, then difference will always be 1 itself.
    // And `ans` will never be updated.
    if (ans == -1)
        return (size + 1);

    return (ans + 1);
}



int main()
{
    int N = 10;
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int ans = missingElement(arr, size);
    cout << "Missing Element is: " << ans;

    return 0;
}