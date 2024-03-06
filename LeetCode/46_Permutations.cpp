/* Given an array `nums` of distinct integers, return all the possible permutations. */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    ans.push_back(nums); // Include initial permutation as well.

    while (next_permutation(nums.begin(), nums.end()))
        ans.push_back(nums);

    return ans;
}



int main()
{
    vector<int> nums = {1, 3, 2};
    vector<vector<int>> ans;
    ans = permute(nums);

    for (int x = 0; x < ans.size(); x++)
    {
        for (int y = 0; y < ans[x].size(); y++)
            cout << ans[x][y] << " ";
        cout << endl;
    }

    return 0;
}