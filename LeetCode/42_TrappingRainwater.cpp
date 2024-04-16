#include <bits/stdc++.h>
using namespace std;


// BRUTE FORCE:
// Time: O(N*N) as 2 nested for loops used.
// Time limit exceeds!
// Space: O(1)
int trap1(vector<int> &height)
{
    int n = height.size();
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i; // For second nested for loop.
        int left_max = 0, right_max = 0;

        while (j >= 0)
        {
            // For searching maximum left elevation.
            left_max = max(left_max, height[j]);
            j--;
        }
        j = i; // Reassign j to i.
        while (j < n)
        {
            // For searching maximum right elevation.
            right_max = max(right_max, height[j]);
            j++;
        }
        water += min(left_max, right_max) - height[i];
    }
    return water;
}


// BETTER APPROACH:
// Iterating through every element to find its left and right maximum takes O(N*N) time.
// Instead, precompute both values in 2 extra arrays in O(N) time.

// Time: O(N) + O(N)+ O(N) = O(3N) = O(N) as only one for loop used.
// Space: O(2N) as two extra arrays created.
int trap2(vector<int> &height)
{
    int n = height.size();
    int pre[n];
    pre[0] = height[0];
    int suf[n];
    suf[n - 1] = height[n - 1];
    int water = 0;

    for (int i = 1; i < n; i++)
        pre[i] = max(height[i], pre[i - 1]); // Store the maximum height to the left of height[i].

    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(height[i], suf[i + 1]); // Store the maximum height to the right of height[i].

    for (int i = 0; i < n; i++)
        water += min(pre[i], suf[i]) - height[i];

    return water;
}


// OPTIMAL APPROACH:
// In this approach, two pointers, left and right, traverse the entire array.
// No use of extra space arrays.
// We update the `leftMax` and `rightMax` simultaneously, reducing space complexity.

// Time: O(N)
// Space: O(1)
int trap3(vector<int> &height)
{
    int n = height.size();
    int l = 0, r = n - 1;
    int left_max = 0, right_max = 0;
    int water = 0;

    while (l <= r) // Two-pointer approach.
    {
        if (height[l] <= height[r])
        {
            if (height[l] >= left_max)
                left_max = height[l]; // Found a greater `left_max` value so updating it.
            else
                water += left_max - height[l];
            l++; // Left pointer is moved forward regardless.
        }
        else
        {
            if (height[r] >= right_max)
                right_max = height[r]; // Found a greater `right_max` value so updating it.
            else
                water += right_max - height[r];
            r--; // Right pointer is moved backwards regardless.
        }
    }
    return water;
}


int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans1 = trap1(height);
    cout << ans1 << endl;
    int ans2 = trap2(height);
    cout << ans2 << endl;
    int ans3 = trap3(height);
    cout << ans3 << endl;

    return 0;
}