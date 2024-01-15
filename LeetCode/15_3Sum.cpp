#include <bits/stdc++.h>
using namespace std;

void print2D(vector<vector<int>> V, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << V[i][j] << "  ";
        cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int target = 0;
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            int pair_sum = target - x;
            while (s < e)
            {
                if ((nums[s] + nums[e]) > pair_sum)
                    e--;
                else if ((nums[s] + nums[e]) < pair_sum)
                    s++;
                else
                {
                    // Create a vector of x, nums[s], nums[e].
                    answer.push_back({x, nums[s], nums[e]});
                    while ((s < e) && (nums[s] == nums[s + 1]))
                        s++;
                    while ((s < e) && (nums[e] == nums[e - 1]))
                        e--;
                    // Move both pointers to search more triplets.
                    s++;
                    e--;
                }
            }
            // We must remove duplicate pairs, which will exist only if there is a duplicate number.
            // In sorted array, check for duplicate adjacent elements. If exist, skip it.
            while ((i + 1 < nums.size()) && (nums[i + 1] == nums[i]))
                i++;
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution obj1;
    vector<vector<int>> answer;
    answer = obj1.threeSum(nums);
    print2D(answer, 3, 3);

    return 0;
}
