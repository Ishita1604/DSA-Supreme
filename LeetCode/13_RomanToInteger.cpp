#include <bits/stdc++.h>
using namespace std;

// Time: O(n) for traversing through the string.
// Space: O(n) as map contains constant number of key-value pairs.


int romanToInt(string s)
{
    unordered_map<char, int> umap =
        {{'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    int n = s.length();
    int sum = umap[s[n - 1]]; // Initial sum is set to the last digit as nothing exists to its right, so it's always added.

    for (int i = n - 2; i >= 0; i--) // Iterate the string backwards.
    {
        char key = s[i];
        char next_key = s[i + 1];
        if (umap[key] < umap[next_key])
            sum -= umap[key]; // If current numeral on left is smaller than the next one in right, subtract it from the sum.
        else
            sum += umap[key]; // Else, add it.
    }
    return sum;
}


int main()
{
    string s = "XIV";
    int ans = romanToInt(s);
    cout << ans;

    return 0;
}
