#include <bits/stdc++.h>
using namespace std;

// Number of Rounds in Insertion Sort = N - 1.
// Every element is chosen and inserted at its correct position.
// Time: O(N^2)
// Time: O(N) in best-case as outer loop runs N times, and inner loop runs only once for every round before breaking.
// Space: O(1)


int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    // Starting from round = 1 as round = 0 can't compared or inserted.
    for (int round = 1; round < n; round++) // Outer loop for each round.
    {
        // STEP 1 - Fetch:
        int val = arr[round];
        // STEP 2 - Compare:
        int j;
        for (j = round - 1; j >= 0; j--) // Inner loop for shifting when the element to its right is greater.
        {
            if (arr[j] > val)
                // STEP 3 - Shift:
                arr[j + 1] = arr[j];
            else
                break; // Stop shifting if the current element is smaller than the value to be inserted.
        }
        // STEP 4 - Copy:
        arr[j + 1] = val; // Update j pointer to j + 1 because it's positioned one position before the insertion point.
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";

    return 0;
}