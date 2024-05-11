/**** Aggressive Cows Problem ****/

#include <bits/stdc++.h>
using namespace std;

// Given an array of stall positions and an integer `k` representing the number of aggressive cows.
// Assign stalls to the cows in a way that maximizes the minimum distance between any two cows.
// MINIMUM TO MAXIMUM!

// Binary Search is applied in range 0 to difference of maximum and minimum element of the array i.e. positions of the cows.
// Time: O(N*logS) where S is the difference between the maximum and minimum positions of the stalls.


bool isPossibleSolution(vector<int> &stalls, int n, int k, int sol)
{
    // Check if we can we place `k` cows at atleast `sol` minimum distance.
    int count = 1;
    int pos = stalls[0];        // Both cows initially placed at zeroth index.
    for (int i = 1; i < n; i++) // Start placing second cow forward.
    {
        if (stalls[i] - pos >= sol)
        {
            count++;
            pos = stalls[i]; // Position of last cow saved as one more can has been placed.
        }
        if (count == k) // All cows have been allocated.
            return true;
    }
    return false;
}


int solve(int n, int k, vector<int> stalls)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls[n - 1] - stalls[0]; // End is given by maximum position - minimum position.
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isPossibleSolution(stalls, n, k, mid))
        {
            ans = mid;   // Store the answer.
            s = mid + 1; // Search right.
        }
        else
            e = mid - 1; // Search left.
    }
    return ans;
}


int main()
{
    int n = 5, k = 3;
    vector<int> stalls = {10, 1, 2, 7, 5};
    cout << solve(n, k, stalls) << endl;

    return 0;
}