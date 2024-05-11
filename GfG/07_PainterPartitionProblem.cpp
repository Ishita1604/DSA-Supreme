/**** Painter Partition Problem ****/

#include <bits/stdc++.h>
using namespace std;

// Same as Book Allocation Problem!
// Paint n boards of different lengths with k painters.
// Each painter takes 1 unit time to paint 1 unit of the board.
// Find the minimum time to complete the job, with the constraint that each painter only paints continuous boards.

// Time: O(N*logS) where S is the time required to paint all the boards i.e. sum of each board's time.
// Binary Search is applied in [0, S] search space.


bool isPossibleSolution(int arr[], int n, int k, long long sol)
{
    long long timeSum = 0;
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol)
            return false;
        if (timeSum + arr[i] > sol)
        {
            count++;
            timeSum = 0;
            timeSum = arr[i];
            if (count > k)
                return false;
        }
        else
            timeSum += arr[i];
    }
    return true;
}


long long minTime(int arr[], int n, int k)
{
    long long s = 0;
    long long e = 0;
    long long ans = -1;
    for (int i = 0; i < n; i++)
        e += arr[i];
    while (s <= e)
    {
        long long mid = s + (e - s) / 2;
        if (isPossibleSolution(arr, n, k, mid))
        {
            // Store and search left for minimum time.
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}


int main()
{
    int n = 5, k = 3;
    int arr[n] = {5, 10, 30, 20, 15};
    cout << minTime(arr, n, k) << endl;

    return 0;
}