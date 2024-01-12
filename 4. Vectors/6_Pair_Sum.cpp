#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

void print(vector<int> arr, int size)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "  ";
}

vector<int> twoSum1(vector<int> &nums, int target)
{
    // BRUTE FORCE APPROACH:
    // Time: O(n^2)
    // Space: O(1)

    // 1) Find all pairs.
    // 2) Check their sum.
    // 3) Remember, `i` goes from 0 to size, but `j` goes (i+ 1) to size.

    // Outer loop finds pair's first element.
    // Inner loop finds pair's second element.
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            // Print all loops.
            // cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            if (nums[i] + nums[j] == target)
                // cout << "Pair found: (" << arr[i] << "," << arr[j] << ")" << endl;
                return {i, j}; // Returning a vector of indices of correct elements.
        }
    }
    return {-1, -1};
}



vector<int> twoSum2(vector<int> &nums, int target)
{
    // HASH MAP APPROACH:
    // Time: O(n)
    // Space: O(n)

    // 1. Create an unordered map tracking every element to its index. Time is O(n). Space is O(n).
    // 2. Run a for loop and fix a number `x`. Time is O(n).
    // Now we have to find (y == target - x) in the map, in the elements part!
    // 3. If `y` exists return it, else move to next iteration of `x`.

    // Step 1:
    unordered_map<int, int> umap;
    //            ↑     ↑
    //            Key,  Element

    for (int i = 0; i < nums.size(); i++)
    {
        umap[nums[i]] = i;
        // umap[Element] = Key;

        // Map after processing each element in the input vector:
        // {11: 0, 4: 1, 6: 2, 5: 3, 8: 4, 9: 5, 3: 6}
    }

    // Step 2:
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int y = target - x;
        if (umap.find(y) != umap.end())
            return {i, umap[y]}; // Return indices of x of y.
    }
    return {-1, -1};
}



vector<int> twoSum3(vector<int> &nums, int target)
{
    // 2 POINTER APPROACH:
    // Time: O(nlogn)
    // Space: O(n) as pair and vector created.

    // 1) Save each element and its index as a pair.
    // 2) Then make a vector of each pair.
    // 3) Sort by element.
    // 4) Assign `start` and `end` pointers.
    // 5) If (s + e) > target => (end--).
    // Else (start++).

    vector<pair<int, int>> v; // Vector of type `pair`.
    pair<int, int> pair1;     //  <Element, Index>
    for (int i = 0; i < nums.size(); i++)
    {
        pair1.first = nums[i]; // Element
        pair1.second = i;      // Index
        v.push_back({pair1.first, pair1.second});
    }

    sort(v.begin(), v.end());
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        if ((v[start].first + v[end].first) > target)
            end--;

        else if ((v[start].first + v[end].first) < target)
            start++;

        else // (start + end == target)
            return {v[start].second, v[end].second};
    }

    return {-1, -1};
}




int main()
{
    vector<int> nums = {11, 4, 6, 5, 8, 9, 3};
    int target = 9;

    // vector<int> ans1 = twoSum1(nums, target);
    // print(ans1, ans1.size());

    // vector<int> ans2 = twoSum2(nums, target);
    // print(ans2, ans2.size());

    vector<int> ans3 = twoSum3(nums, target);
    print(ans3, ans3.size());

    return 0;
}
