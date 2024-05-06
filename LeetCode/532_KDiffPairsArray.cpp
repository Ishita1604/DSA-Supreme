#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH:
// Time: O(N*N)
// Space: O(N*N) as set of pairs is used.
int findPairs1(vector<int> &nums, int k)
{
    set<pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (abs(nums[i] - nums[j]) == k)
                ans.insert({nums[i], nums[j]});
        }
    }
    return ans.size();
}


// TWO POINTER APPROACH:
// Time: O(N*logN) as we sort array in O(N*NlogN) and iterate it just once in O(N).
// Space: O(N*N) as we create set for unique pairs.
int findPairs2(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    set<pair<int, int>> ans;
    while (j < nums.size())
    {
        if (i == j)
            j++; // Because in constraint it is saying (i != j)!
        int diff = nums[j] - nums[i];
        if (diff == k)
        {
            // cout << nums[j] << "  " << nums[i] << endl;
            ans.insert({nums[i], nums[j]});
            i++;
            j++; // This pair is stored, now move on to next pair.
        }
        else if (diff > k)
        {
            // Reduce the difference.
            i++; // We won't do j-- to preserve uniqueness as we've already explored that solution.
        }
        else // (diff < k)
        {
            // Increase the difference.
            j++; // Again not i-- to preserve uniqueness.
        }
    }
    return ans.size();
}


// OPTIMAL APPROACH:
// Time: O(N*logN) as we sort array and iterate once.
// Space: O(N*N) as set is used.
// The approach is that in sorted array, the element we are standing on is nums[i] and we already have k.
// So if (nums[i] + k) exists, which is nothing but corresponding nums[j], then the K-different pair exists!
int binarySearch(vector<int> nums, int start, int el)
{
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == el)
            return mid;
        else if (el > nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int findPairs3(vector<int> &nums, int k)
{
    set<pair<int, int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        // In right side that is (i + 1) search for (a[i] + k):
        if (binarySearch(nums, i + 1, nums[i] + k))
            ans.insert({nums[i], nums[i] + k});
    }
    return ans.size();
}


int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int k = 2;
    // cout << findPairs1(nums, k);
    // cout << findPairs2(nums, k);
    cout << findPairs3(nums, k);

    return 0;
}