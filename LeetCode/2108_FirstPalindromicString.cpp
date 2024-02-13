/*** Given an array of strings words, return the first palindromic string in the array.
If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward. ***/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string swapString(string i)
    {
        int s = 0;
        int e = i.length() - 1;
        while (s < e)
        {
            swap(i[s], i[e]);
            s++;
            e--;
        }
        return i;
    }

    string firstPalindrome(vector<string> &words)
    {
        int i;
        for (i = 0; i < words.size(); i++)
        {
            if (swapString(words[i]) == words[i])
                return words[i];
        }
        return "";
    }
};

int main()
{
    vector<string> words = {"notapalindrome", "racecar"};
    Solution obj;
    string ans = obj.firstPalindrome(words);
    cout << ans;

    return 0;
}