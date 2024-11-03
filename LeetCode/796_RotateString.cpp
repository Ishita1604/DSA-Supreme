#include <bits/stdc++.h>
using namespace std;

/* __________________________________________________________________________________________
LeetCode 796: Rotate String
Link: [https://leetcode.com/problems/rotate-string/]

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.


Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false

_____________________________________________________________________________________________
*/


class Solution
{
public:
    // APPROACH 1: Keep popping and appending till strings match, if they don't, return false.
    bool rotateString(string s, string goal)
    {
        string c = "";
        int i = 0;
        while (i < s.length())
        {
            c = s[0];
            s.erase(0, 1);
            s.append(c, 0, 1);
            i++;
            if (s == goal) break;
        }
        if (s == goal) return true;
        return false;
    }

    // APPROACH 2: Concatenate `s` with itself and if `goal` is a substring, return true, else false.
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size()) return false;
        string combi = s + s;
        if (combi.find(goal) != string::npos) return true;
        return false;
    }
};


int main()
{
    Solution obj;
    string s = "abcde";
    string goal = "bcdea";
    bool res = obj.rotateString(s, goal);
    cout << res << endl;

    return 0;
}