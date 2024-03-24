/*****    LeetCode 724: Find Pivot Index    *****/

// Find the index where sum of elements to its left equals to the sum on right.
// If at array edge, sum is zero.

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int m = e + (s - e) / 2;

    while (s <= e)
    {
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < m; i++)
            sum1 += nums[i];
        for (int i = m + 1; i < n; i++)
            sum2 += nums[i];

        if (sum1 == sum2)
            return m;
        if (sum1 < sum2)
            s++;
        else
            e--;

        m = e + (s - e) / 2;
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 1, -1};
    pivotIndex(nums);

    return 0;
}