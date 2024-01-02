#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void print(vector<int> arr, int size)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "  ";
}

vector<int> twoSum1(vector<int> &nums, int target)
{
    // BRUTE FORCE APPROACH:

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

    // 1. Create an unordered map tracking every element to its index.
    // 2. Run a for loop and fix a number `x`.
    // Now we have to find (y == target - x) in the map, in the elements part!
    // 3. If `y` exists return it, else move to next iteration of `x`.

    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]] = i;
        // Map after processing each element in the input vector:
        // {11: 0, 4: 1, 6: 2, 5: 3, 8: 4, 9: 5, 3: 6}
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int y = target - x;
        if (map.find(y) != map.end())
            return {i, map[y]};
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

    return 0;
}
