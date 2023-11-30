/******* Sort an Array of 0s, 1s and 2s | Dutch National Flag Problem *******/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        /*
        // METHOD 1: Sort the vector.
        // Time: O(nlogn) as it is a combination of Quick, Heap & Insertion Sort.
        // Space: O(n)
        sort(nums.begin(), nums.end());
        */




        /*
        // METHOD 2: Counting Method.
        // Time: O(n) => O(n + zeroes + ones + twos) => O(n)
        // As in worst case, zeroes + ones + twos = n, resulting in O(n + n) or O(2n) or simple O(n).
        // Space: O(1)

        // **** COUNT ****
        int zeroes = 0, ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeroes++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }

        // **** SPREAD ****
        // Over write the values.
        // For loop not used here.
        // As we don't know how many values of zeroes, ones, twos are there.
        int i = 0;
        while (zeroes--)
        {
            nums[i] = 0;
            i++;
        }
        while (ones--)
        {
            nums[i] = 1;
            i++;
        }
        while (twos--)
        {
            nums[i] = 2;
            i++;
        }
        */





        /*
        // METHOD 3: Inplace Sort / Shuffle / 3 Pointer.
        int l = 0;
        int m = 0;
        int h = nums.size() - 1;

        while (m <= h)
        {
            if (nums[m] == 0)
            {
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if (nums[m] == 1)
            {
                m++;
            }
            else
            { // nums[m] == 2
                swap(nums[m], nums[h]);
                h--;
                // Not m++ as it is not necessary that the swapped number is 1 itself.
            }
        }
        */
    }
};

int main()
{
    vector<int> nums = {2, 0, 1, 2, 2, 1, 1, 0, 1, 0};
    Solution obj;
    obj.sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i];

    return 0;
}
