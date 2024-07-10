#include <bits/stdc++.h>
using namespace std;

// Time: O(N*logN)
// Space: O(1)
bool isAnagram1(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
        return true;
    else
        return false;
}

// Time: O(N)
// Space: O(1)
bool isAnagram2(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> map;

    for (int i = 0; i < s.size(); i++)
        map[s[i]]++;

    for (int i = 0; i < t.size(); i++)
    {
        if (map.find(t[i]) == map.end() || map[t[i]] == 0)
            return false;
        else
            map[t[i]]--;
    }
    return true;
}

int main()
{
    string s = "anagram";
    string t = "naganam";
    // if (isAnagram1(s, t))
    if (isAnagram2(s, t))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;
    return 0;
}