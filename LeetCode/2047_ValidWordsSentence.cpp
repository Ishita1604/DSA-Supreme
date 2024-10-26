#include <bits/stdc++.h>
using namespace std;


/* __________________________________________________________________________________________
LeetCode 2047: Number of Valid Words in a Sentence
Link: [https://leetcode.com/problems/number-of-valid-words-in-a-sentence/]

A sentence consists of lowercase letters ('a' to 'z'), digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), and spaces (' ') only.
Each sentence can be broken down into one or more tokens separated by one or more spaces ' '.

A token is a valid word if all three of the following are true:
    - It only contains lowercase letters, hyphens, and/or punctuation (no digits).
    - There is at most one hyphen '-'. If present, it must be surrounded by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
    - There is at most one punctuation mark. If present, it must be at the end of the token ("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
    - Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".

Given a string sentence, return the number of valid words in sentence.


Example 1:
Input: sentence = "cat and  dog"
Output: 3
Explanation: The valid words in the sentence are "cat", "and", and "dog".

Example 2:
Input: sentence = "!this  1-s b8d!"
Output: 0
Explanation: There are no valid words in the sentence. "!this" is invalid because it starts with a punctuation mark. "1-s" and "b8d" are invalid because they contain digits.

Example 3:
Input: sentence = "alice and  bob are playing stone-game10"
Output: 5
Explanation: The valid words are "alice", "and", "bob", "are", and "playing". "stone-game10" is invalid because it contains digits.

_____________________________________________________________________________________________
*/


/*
Important functions:
// remove(v.begin(), v.end(), el) ------ STD function
// isdigit(x) ------ STD function
// islower(x) ------ STD function
// v.erase(idx) ---- Vector function
// v.clear() -- clear all -- Vector function

// What all to check:
// Spaces
// Lowercase (Not needed)
// Digits
// Hyphen
// ! . ,



*/


class Solution
{
public:

    // Step 1: Preparing the tokens (from spaces) into a vector of strings.
    // Step 2: Separate functions for digit checking, hyphen, and punctuation marks.

    bool checkDigits(const string &t)
    {
        for (auto te : t)
        {
            if (te >= 48 && te <= 57) return false;
            // if (isdigit(te)) return false;
        }
        return true;
    }

    bool checkHyphens(const string &t)
    {
        int m = t.length();
        int hcount = 0;
        if (t[0] == '-' || t[m - 1] == '-') return false;

        for (int i = 1; i < m - 1; i++)
        {
            if (t[i] == '-')
            {
                hcount++;
                if (hcount > 1) return false;
                if (!islower(t[i - 1]) || !islower(t[i + 1])) return false;
            }
        }
        return true;
    }

    bool checkPunc(const string &t)
    {
        int m = t.length();
        int pcount = 0;
        for (auto te : t)
        {
            if (te == '!' || te == '.' || te == ',') pcount++;
        }
        if (pcount == 0) return true;
        if (pcount > 1) return false; // Reject if more than one present.

        if ((pcount == 1 && (t[m - 1] != '!')) && (pcount == 1 && (t[m - 1] != '.')) && (pcount == 1 && (t[m - 1] != ',')))    return false;
        return true;
    }

    int countValidWords(string sentence)
    {
        int n = sentence.length();
        string t;
        vector<string> tv;
        int count = 0;
        // Push token to vector.
        for (int i = 0; i < n; i++)
        {
            if ((i != n - 1) && (sentence[i] != ' ' && sentence[i + 1] != ' '))    t.push_back(sentence[i]);
            else if ((sentence[i] != ' ' && sentence[i + 1] == ' ') || (sentence[i] != ' ' && (i == n - 1)))
            {
                t.push_back(sentence[i]);
                tv.push_back(t);
                t.clear();
            }
            else continue;
        }

        for (auto &t : tv)
        {
            if (!checkDigits(t) || !checkHyphens(t) || !checkPunc(t))    count++;
        }
        return tv.size() - count;
    }
};

int main()
{
    Solution obj;
    string sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.";
    int count = obj.countValidWords(sentence);
    cout << "Count of valid words is/are: " << count << endl;

    return 0;
}