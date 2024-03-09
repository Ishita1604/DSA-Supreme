#include <bits/stdc++.h>
using namespace std;

// Given an array `nums` containing `n` distinct numbers in the range [0, n].
// Return the only number in the range that is missing from the array.


class Solution
{
public:
    // TIME: O(n^2)
    int missingNumber1(vector<int> &nums)
    {
        /** 1. BRUTE FORCE METHOD **/
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {
            int element = i;
            if (find(nums.begin(), nums.end(), element) == nums.end()) // Not present.
                return element;
        }
        return -1;
    }


    // TIME: O(n)
    int missingNumber2(vector<int> &nums)
    {
        /** 2. SUM AND SUBTRACT METHOD **/
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i <= n; i++)
            sum += i;

        for (int i = 0; i < n; i++)
            sum -= nums[i];

        return sum;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {4, 1, 0, 3, 5};
    // int ans1 = obj.missingNumber1(nums);
    // cout << "Missing Number is: " << ans1 << endl;


    int ans2 = obj.missingNumber2(nums);
    cout << "Missing Number is: " << ans2 << endl;

    return 0;
}
