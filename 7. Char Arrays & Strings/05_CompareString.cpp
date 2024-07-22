#include <bits/stdc++.h>
using namespace std;

bool compareStrings(string a, string b)
{
    if (a.length() != b.length())
        return false;
    else
    {
        int j = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[j])
                return false;
            j++;
        }
    }
    return true;
}

int main()
{
    string word1 = "Success";
    string word2 = "Easy";
    bool ans = compareStrings(word1, word2);
    if (ans)
        cout << "Strings are exactly SAME!";
    else
        cout << "Strings are NOT same!";

    return 0;
}