// Given an array `nums` containing `n` distinct numbers in the range [0, n].
// Return the only number in the range that is missing from the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
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
};

int main()
{
    Solution obj1;
    vector<int> nums = {0, 1, 4, 3, 4, 5};
    int answer = obj1.missingNumber(nums);
    cout << "Missing Number is: " << answer << endl;
    return 0;
}