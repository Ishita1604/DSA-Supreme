/******** Peak Index in a Mountain Array ********

 * Time: O(log(arr.length)) thus using Binary Search.

 * Components of the Mountain:
    1. Line 1 (Ascending)
    2. Peak
    3. Line 2 (Descending)

****/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        int m = s + (e - s) / 2;

        while (s < e)
        {
            if (arr[m] < arr[m + 1])
            {
                // Definitely not Peak element.
                // This is Line 1.
                s = m + 1; // Search right.
            }
            else
            {
                // Either Peak or Line 2.
                e = m;
            }
            m = s + (e - s) / 2;
        }
        return s;
    }
};

int main()
{
    vector<int> arr = {1, 14, 29, 12, 10, 5, 3, 1};
    int n = arr.size();

    Solution obj;
    int ans = obj.peakIndexInMountainArray(arr);
    cout << "Peak Element is at Index: " << ans << endl;

    return 0;
}