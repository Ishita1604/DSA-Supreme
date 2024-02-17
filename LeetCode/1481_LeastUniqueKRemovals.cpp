/***** LEAST NUMBER OF UNIQUE INTEGERS AFTER K REMOVALS:
    Given an array of integers arr and an integer k.
    Find the least number of unique integers after removing exactly k elements.

# Example 1:
    Input: arr = [5,5,4], k = 1
    Output: 1
    Explanation: Remove the single 4, only 5 is left.
*****/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool sortByFreq(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }

    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> umap;
        // Store frequencies of each element.
        for (int i = 0; i < arr.size(); i++)
            umap[arr[i]]++;

        // Hash map can't directly be sorted, so make a vector of pair.
        vector<pair<int, int>> v(umap.begin(), umap.end());
        int n = v.size();

        // Now sort by descending order of frequency.
        sort(v.begin(), v.end(), sortByFreq);
        // cout << "Vector After Sorting:" << endl;
        // for (int i = 0; i < v.size(); i++)
        //     cout << v[i].first << " " << v[i].second << endl;
        // cout << endl;

        // Run loop `k` times and decrement the frequency from end.
        for (int i = 0; i < n && k > 0; i++)
        {
            while (v[n - 1 - i].second > 0 && k > 0)
            {
                v[n - 1 - i].second--;
                k--;
            }
        }

        // cout << "Vector After Popping:" << endl;
        // for (int i = 0; i < v.size(); i++)
        //     cout << v[i].first << " " << v[i].second << endl;
        // cout << endl;

        int countDistinct = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second)
                countDistinct++;
        }
        return countDistinct;
    }
};

int main()
{
    // vector<int> arr{4, 3, 1, 1, 3, 3, 2};
    // vector<int> arr{2, 1, 1, 3, 3, 3};
    // vector<int> arr{1, 1};
    vector<int> arr{5, 5, 4};
    int k = 1;
    Solution obj;
    int ans = obj.findLeastNumOfUniqueInts(arr, k);
    cout << ans;

    return 0;
}