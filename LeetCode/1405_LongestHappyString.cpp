#include <bits/stdc++.h>
using namespace std;


/* __________________________________________________________________________________________
LeetCode 1405: Longest Happy String
Link: [https://leetcode.com/problems/longest-happy-string]

A string s is called happy if it satisfies the following conditions:
    - s only contains the letters 'a', 'b', and 'c'.
    - s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    - s contains at most a occurrences of the letter 'a'.
    - s contains at most b occurrences of the letter 'b'.
    - s contains at most c occurrences of the letter 'c'.

Given three integers a, b, and c, return the longest possible happy string.
If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
A substring is a contiguous sequence of characters within a string.


Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

_____________________________________________________________________________________________
*/


class Solution
{
#define pic pair<int, char>
public:
    string longestDiverseString(int a, int b, int c)
    {
        // Longest possible happy string length <= (a + b + c).
        // Greedy Approach:
        // Intuition: First try to use character with highest frequency as much as we can.
        // Use max heap to avoid comparison and ensure each time a pair of maximum frequency character is selected.
        // Then check condition if 3 same consecutive characters appear, if yes, move on to next highest-frequency character.

        // TIME: O(a + b + c)
        // SPACE: O(1)
        string res;
        priority_queue<pic> maxheap;
        // Create initial nodes of the max heap.
        if (a > 0) maxheap.push({a, 'a'});
        if (b > 0) maxheap.push({b, 'b'});
        if (c > 0) maxheap.push({c, 'c'});

        // Forming longest happy string.
        while (!maxheap.empty())
        {
            // Return frequency and character with maximum count, which will be stored at heap's top.
            // auto [freq, ch] = maxheap.top();
            pair<int, char> top = maxheap.top();
            int freq = top.first;
            char ch = top.second;
            maxheap.pop();

            int n = res.size();
            // Check if current character has appeared in previous two indices of the string.
            if (n >= 2 && res[n - 1] == ch && res[n - 2] == ch)
            {
                if (maxheap.empty()) break;
                // If yes, move on to next highest.
                // auto [next_freq, next_ch] = maxheap.top();
                pair<int, char> top = maxheap.top();
                int next_freq = top.first;
                char next_ch = top.second;
                maxheap.pop();

                res.push_back(next_ch);
                next_freq--;
                if (next_freq > 0)
                    maxheap.push({next_freq, next_ch});
            }
            else
            {
                res.push_back(ch);
                freq--; // Node is popped already, simply decrement.
            }
            if (freq > 0) maxheap.push({freq, ch});
        }

        return res;
    }
};


int main()
{
    int a = 9, b = 2, c = 1;
    Solution obj;
    string res = obj.longestDiverseString(a, b, c);

    cout << "The longest happy string is: " << res << endl;

    return 0;
}
