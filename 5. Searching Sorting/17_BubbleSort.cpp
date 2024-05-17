#include <bits/stdc++.h>
using namespace std;

// Number of Rounds in Bubble Sort = N - 1.
// In each `ith` round, we place `ith` largest element to its correct position.
// Time: O(N^2)
// Time: O(N) in best-case as flag `swapped` has been used to prevent further comparisons.
// Space: O(1)


int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) // Outer loop for (N - 1) Rounds.
    {
        bool swapped = false;                // To optimize for best-case scenario (array already sorted) into O(N) time.
        for (int j = 0; j < n - i - 1; j++) // Inner loop to compare adjacent elements till (N - i - 1).
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            if (swapped == false) // No swapping means array is sorted.
                break;            // As no further rounds needed.
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";

    return 0;
}