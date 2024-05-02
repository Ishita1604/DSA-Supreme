#include <bits/stdc++.h>
using namespace std;
// Time: O(N*logN + N)

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // O(N*logN)
        for (int i = 0; i < n; i++)     // O(N)
        {
            // First least negative number:
            if (nums[i] < 0)
            {
                auto it = find(nums.begin(), nums.end(), abs(nums[i])); // O(N)
                if (it != nums.end())                                   // Found the positive equivalent.
                    return abs(nums[i]);
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {-4, -2, -1, 0, 6, 7, 8, 11};
    Solution obj;
    cout << obj.findMaxK(nums);

    return 0;
}