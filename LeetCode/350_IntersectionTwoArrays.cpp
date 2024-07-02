#include <bits/stdc++.h>
using namespace std;

// Time: O(N*logN) for in-place vector sorting.
// Space: O(log*N) for the recursion stack of sort() function.
// Using a pointer each to traverse both arrays to reduce time from O(N*N) to O(N*logN)
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    int i = 0;
    int j = 0;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 4, 6};
    vector<int> nums2 = {2, 4, 6, 8};
    vector<int> ans = intersect(nums1, nums2);
    for (auto i : ans)
        cout << i << "  ";
    cout << endl;
    return 0;
}
