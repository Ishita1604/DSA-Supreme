/****    LeetCode 540: Single Element in a Sorted Array ****/
/****    Or, Find Odd Occurring Element in an Array     ****/

// [File: DSA-Supreme/5. Searching Sorting/13_BS_OddOccurrence.cpp] is this same question.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        int mid = (s + e) / 2;

        while (s <= e)
        {
            if (s == e) // Single element.
                return arr[s];
            if (mid % 2 == 0) // Even index.
            {
                // Compare with next element.
                if (arr[mid] == arr[mid + 1])
                    // Search in right.
                    s = mid + 2; // As (mid + 1) already compared.

                else // (arr[mid] != arr[mid + 1])
                    // Search in left.
                    e = mid; // As mid can be answer.
            }
            else // Odd index.
            {
                // Compare with previous element.
                if (arr[mid] == arr[mid - 1])
                    // Search in right.
                    s = mid + 1;

                else
                    // Search in left.
                    e = mid - 1;
            }
            mid = (s + e) / 2;
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {3, 3, 7, 7, 10, 11, 11};
    Solution obj;
    int ans = obj.singleNonDuplicate(arr);
    cout << "Odd Occuring Element is: " << ans << endl;

    return 0;
}