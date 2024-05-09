#include <bits/stdc++.h>
using namespace std;

// Number of Rounds in Selection Sort = N - 1.
// As last iteration has only one element remaining, which means already sorted.
// Time: O(N^2)
// Space: O(1)


int main()
{
    vector<int> arr = {5, 4, 3, 2, 69, 1};
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) // Outer loop for (N - 1) Rounds.
    {
        int minIndex = i;
        for (int j = i; j < n; j++) // Inner loop for minimum of each iteration.
        {
            if (arr[j] < arr[i]) // New minIndex, then store.
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]); // Swap to place the correct element at that position.
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";

    return 0;
}