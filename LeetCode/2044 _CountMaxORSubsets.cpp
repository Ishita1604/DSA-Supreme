#include <bits/stdc++.h>
using namespace std;

/* __________________________________________________________________________________________
LeetCode 2044: Count Number of Maximum Bitwise-OR Subsets
Link: [https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/]

Given an integer array nums, find the maximum possible bitwise OR of a subset of nums.
And return the number of different non-empty subsets with the maximum bitwise OR.
An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
Two subsets are considered different if the indices of the elements chosen are different.
The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

Example 1:
Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3, [3] and [3,1].

Example 2:
Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.

_____________________________________________________________________________________________
*/



class Solution
{
public:
    // ---- Unique Subsets ----
    // void calcSubset(vector<int> &nums, int idx, vector<int> &subset, set<vector<int>> &result)
    // {
    //     if (!subset.empty())    result.insert(subset);
    //     for (int j = idx; j < nums.size(); j++)
    //     {
    //         subset.push_back(nums[j]);
    //         calcSubset(nums, j + 1, subset, result);
    //         subset.pop_back();
    //     }
    // }

    // vector<vector<int>> subsets(vector<int> &nums)
    // {
    //     set<vector<int>> result;
    //     vector<int> subset;
    //     calcSubset(nums, 0, subset, result);
    //     vector<vector<int>> list;
    //     for (auto nums : result)
    //         list.push_back(nums); // 2D list of all possible unique subsets.
    //     return list;
    // }

    // ---- Duplicate Subsets ----
    void calcSubset(vector<int> &nums, vector<vector<int>> &list, vector<int> &subset, int index)
    {
        list.push_back(subset);
        for (int i = index; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            calcSubset(nums, list, subset, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> subset;
        vector<vector<int>> list;
        int index = 0;
        calcSubset(nums, list, subset, index);
        return list; // 2D list of all possible subsets.
    }

    int subsetOR(vector<int> &el)
    {
        int curr_OR = 0; // As 0 OR any number, gives number itself.
        for (int e = 0; e < el.size(); e++)    curr_OR = curr_OR | el[e];
        return curr_OR;
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        vector<vector<int>> list = subsets(nums);
        int max_OR = 0;
        int count = 0;

        // Logic for getting the count of subsets with maximum OR value.
        for (auto &el : list) // Here "el" is each 1D subset vector of "list".
        {
            int curr_OR = subsetOR(el);
            if (curr_OR > max_OR)    count = 0; // Reset count.
            max_OR = max(max_OR, curr_OR);
            if (curr_OR == max_OR)    count++;
        }
        return count;
    }
};



int main()
{
    Solution obj;
    vector<int> nums = {1, 1, 2};
    int count = obj.countMaxOrSubsets(nums);
    cout << "Count of subsets with maximum OR value: " << count << endl;

    return 0;
}