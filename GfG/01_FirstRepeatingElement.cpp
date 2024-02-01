/** Given an array arr[] of size n, find the first repeating element.
The element should occur more than once.
And the index of its first occurrence should be the smallest.

NOTE: The position you return should be according to 1-based indexing.
**/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        unordered_map<int, int> umap;
        // STEP 1. TRAVERSE
        for (int i = 0; i < n; i++)
        {
            // STEP 2. STORE
            umap[arr[i]]++; // For each arr[i] increment the key.
        }

        for (int i = 0; i < n; i++)
        {
            // STEP 3. CHECK
            if (umap[arr[i]] > 1)
            {
                return (i + 1); // As 1 based indexing.
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cout << "Enter the Size: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    Solution obj;
    cout << obj.firstRepeated(arr, n) << "\n";

    return 0;
}
