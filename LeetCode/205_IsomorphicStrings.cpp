#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(2 * n)

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, char> umap;    // Create an unordered map to insert mappings.
    unordered_map<char, bool> visited; // Create a map to keep track of visited characters in t.

    for (int i = 0; i < s.length(); i++)
    {
        char original = s[i];
        char replacement = t[i];

        if (umap.find(original) == umap.end()) // Original not present.
        {
            if (visited[replacement])
                return false; // As replacement already been used, i.e. already been mapped to a different character!
            // Else, replacement not already present in umap.
            umap[original] = replacement; // Insert the mapping.
            visited[replacement] = true;  // Mark replacement as visited.
        }
        else // Original is already present in umap.
        {
            if (umap[original] != replacement) // If it is not mapping to the same character, then false.
                return false;
        }
    }
    // If we break out of the loop without returning false, strings ARE isomorphic.
    return true;
}

int main()
{
    string s = "boo";
    string t = "hyy";
    bool ans = isIsomorphic(s, t);
    if (ans)
        cout << "True";
    else
        cout << "False";

    return 0;
}
