#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n)

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> umap;         // Create hashmap.
    for (int i = 0; i < nums.size(); i++) // Update frequencies.
        umap[nums[i]]++;
    for (int i = 0; i < nums.size(); i++) // Return element of single frequency.
    {
        if (umap[nums[i]] == 1)
            return nums[i];
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    int ans = singleNumber(nums);
    cout << "Element that occurs only once is: " << ans << endl;

    return 0;
}