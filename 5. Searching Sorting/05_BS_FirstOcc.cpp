#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/********** Algorithm: **********/

// If found, store & search left.
// Update `mid` and return `ans`.

int firstOcc(vector<int> v, int target)
{
    int start = 0;
    int end = v.size() - 1;
    int mid = start + ((end - start) / 2);
    int ans = -1;

    while (start <= end)
    {
        if (target == v[mid])
        {
            // Store & search left for another first occurence:
            ans = mid;
            end = mid - 1;
        }
        else if (target > v[mid])
            start = mid + 1; // Search right.
        else
            end = mid - 1; // Search left.

        mid = start + ((end - start) / 2);
    }

    return ans;
}

int main()
{
    vector<int> v{1, 3, 3, 3, 5, 7, 7, 8, 9, 10};
    int target = 7;

    // int ans = firstOcc(v, target);
    // if (ans == -1)
    //     cout << "Not Found!" << endl;
    // else
    //     cout << "Target First Found at Index: " << ans << endl;



    // Using in-built function:
    auto ans = lower_bound(v.begin(), v.end(), target);
    cout << "First Occurance is: " << ans - v.begin();
}