// 2) The code uses the Boyer-Moore Voting Algorithm to find the majority element in the given vector of integers.
// Majority element is that element which appears more than n/2 times.
// However, there is a bug in the code that causes it to return an incorrect result for some inputs.
// Your task is to identify and fix the bug.
// Hint: Incomplete code.

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate, count = 0;
    for (int i = 0; i < nums.size(); i++)
    // Here only count is getting ++ or -- or candidate is being assigned.
    {
        if (count == 0)
            candidate = nums[i];
        if (nums[i] == candidate)
            count++;
        else
            count--;
    }

    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // Code to actually count the number of occurrences of candidate.
        if (nums[i] == candidate)
            count++;
    }

    // And check if candidate occurs more than n/2 times.
    if (count > nums.size() / 2)
        return candidate;
    else
        return -1;
}

int main()
{
    vector<int> nums = {1, 3, 3, 4, 3, 2, 3};
    cout << "The majority element is: " << majorityElement(nums) << endl;
    return 0;
}