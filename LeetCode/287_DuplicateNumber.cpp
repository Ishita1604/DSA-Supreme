/****    LeetCode 287: Find the Duplicate Number    ****/

// Given an array `nums` containing (n + 1) integers, each in the range [1, n] inclusive.
// Only one number is repeated, return this repeated number.
// Don't modify the array & use only constant extra space.


// 1. BRUTE FORCE - 2 Loops.
// 2. Sort & adjacent duplicates method.
// 3. Negative visited method.
// 4. Two-Pointer (Without the sorting) - Implemented here.
// 5. Hash Map.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int end = n - 1;
            while (i < end)
            {
                // If nums[i] is found in remaining array:
                if (nums[i] == nums[end])
                    return nums[i];
                else
                    end--;
            }
        }
        return -1;
    }
};


int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};
    Solution obj1;
    int answer = obj1.findDuplicate(nums);
    cout << "Duplicate Element is: " << answer;

    return 0;
}