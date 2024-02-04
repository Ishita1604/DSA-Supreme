/** Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times.
    You may assume that the majority element always exists in the array.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            umap[nums[i]]++; // Increment the key.
            if (umap[nums[i]] > n / 2)
                return nums[i];
        }
        return -1; // No majority element found.
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << obj.majorityElement(nums);

    return 0;
}