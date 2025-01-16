#include <bits/stdc++.h>
using namespace std;


/* _________________________________________________________________________________________
LeetCode 2425: Bitwise XOR of All Pairings
Link: [https://leetcode.com/problems/bitwise-xor-of-all-pairings/]

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers.
There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2.
Every integer in nums1 is paired with every integer in nums2 exactly once.

Return the bitwise XOR of all integers in nums3.


Example 1:
Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation: A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation: All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0], and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.

_____________________________________________________________________________________________
*/


class Solution
{
public:
    /*  BRUTE FORCE:
        Using 2 for loops. Every element's XOR with every other element.
        TIME: O(m*n) and gives TLE error!
        SPACE: O(1)
    */
    // int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    // {
    //     int xor1 = 0, xor2 = 0;
    //     for (auto &x : nums1)
    //     {
    //         for (auto &y : nums2)
    //         {
    //             xor1 = x ^ y;          // XOR of each num1 and num2 element.
    //             xor2 = xor1 ^ xor2;    // Keep storing final XOR.
    //         }
    //     }
    //     return xor2;
    // }




    /*  USING HASH MAP:
        XOR of a number calculated even number of times gives 0, and odd times gives number itself.
        XOR is associative and commutative.
        TIME: O(m+n) for creating hash map of all elements of nums1 and nums2.
        SPACE: O(n) for iterating hash map.
    */
    // int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    // {
    //     unordered_map<int, long> map;
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     // Frequency map of each element.
    //     for (auto &x : nums1) map[x] += n;
    //     for (auto &y : nums2) map[y] += m;

    //     // In nums3, elements of nums1 appear n times. And of nums2 appear m times.
    //     int ans = 0;
    //     for (auto &el : map)
    //     {
    //         int num = el.first;
    //         int freq = el.second;
    //         if (freq % 2 != 0) ans = ans ^ num; // Only in odd frequency, it gets included in final XOR.
    //     }
    //     return ans;
    // }



    
    /*  CHECKING SIZE OF VECTORS:
        If both are odd, XOR of all elements.
        If both even, answer is 0.
        If one odd one even, answer is XOR of vector of even elements.
        TIME: O(m+n) for computing XOR of all elements in nums1 and nums2.
        SPACE: O(1)
    */
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        int xor1 = 0, xor2 = 0;
        int m = nums1.size();
        int n = nums2.size();

        for (auto &x : nums1) xor1 = x ^ xor1; // XOR of all elements of nums1.
        for (auto &y : nums2) xor2 = y ^ xor2; // XOR of all elements of nums2.

        // These conditions handle all possible odd-even combinations.
        int ans = 0;
        if (m % 2 != 0) ans ^= xor2; // When m is odd. 
        if (n % 2 != 0) ans ^= xor1; // When n is odd.
 
        return ans;
    }
};




int main()
{
    Solution obj;
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    cout << obj.xorAllNums(nums1, nums2) << endl;

    return 0;
}
