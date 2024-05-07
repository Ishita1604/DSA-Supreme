#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE:
// Sort the array based on difference of each element and x.
// Then return the first k elements of this vector.



// TWO POINTER APPROACH:
// Time: O(N-K)
// Space: O(K) to return the answer vector.
vector<int> findClosestElements2(vector<int> &arr, int k, int x)
{
    int l = 0;
    int h = arr.size() - 1;
    while (h - l >= k)
    {
        if (x - arr[l] > arr[h] - x) // Difference at low side is greater.
            l++;                     // Reduce the difference by moving low pointer ahead.
        else                         // Difference at high side is greater.
            h--;                     // Reduce the difference by moving high pointer backwards.
    }
    return vector<int>(arr.begin() + l, arr.begin() + h + 1); // Adding 1 as it returns array with one less element.
}



// BINARY SEARCH APPROACH:
// Time: O(N*logN + K)
// Space: O(K) to return the answer vector.
// Goal is to expand window till size k.
int lowerBound(vector<int> &arr, int x)
{
    int l = 0;
    int h = arr.size() - 1;
    // Very important step:
    int ans = arr.size(); // Not ans = -1 as in some cases we never reach the last elemenet when it IS the lower bound.
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (x <= arr[mid])
        {
            ans = mid;   // Store as maybe an answer.
            h = mid - 1; // Keep searching left.
        }
        else
            l = mid + 1; // Search in right.
    }
    return ans;
}

vector<int> findClosestElements3(vector<int> &arr, int k, int x)
{
    int h = lowerBound(arr, x);
    int l = h - 1;
    while (k--) // Important step.
    {
        if (l < 0)                        // When low can't be assigned further left as out of range error.
            h++;                          // Rather move high forward to expand window size.
        else if (h >= arr.size())         // Out of range error on h's side.
            l--;                          // Move it backwards.
        else if (x - arr[l] > arr[h] - x) // Difference is already greater at low side, so we can't move it to more left.
            h++;                          // Thus, move the high pointer forward.
        else                              // Difference at high side is greater, so we can't move it to more right.
            l--;                          // Thus, move left.
    }
    // Now after k iterations, l is one position behind, and k is one position ahead.
    return vector<int>(arr.begin() + l + 1, arr.begin() + h);
}



int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ans;
    int k = 4;
    int x = 3;
    // ans = findClosestElements1(arr, k, x);
    // ans = findClosestElements2(arr, k, x);
    ans = findClosestElements3(arr, k, x);
    for (auto i : ans)
        cout << i << "  ";

    return 0;
}