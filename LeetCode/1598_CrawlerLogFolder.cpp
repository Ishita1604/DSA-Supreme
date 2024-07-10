#include <bits/stdc++.h>
using namespace std;

// Time: O(N)
// Space: O(1)
int minOperations(vector<string> &logs)
{
    int count = 0;
    regex x("^[a-z0-9]+/$");
    // Folder name starts with lowercase letter or digit, any number of times, and ends with forward slash.
    // Starts with: ^
    // Ends with: $
    // Any number of times: +
    for (int i = 0; i < logs.size(); i++)
    {
        if (logs[i] == "../" && (count > 0))
            count--;
        else if (regex_match(logs[i], x))
            count++;
        else // Skips "./" operations or "../" operations when count is 0.
            continue;
    }
    return count;
}

int main()
{
    vector<string> logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    // vector<string> logs = {"./", "../", "./"};
    int ans = minOperations(logs);
    cout << "Use the change folder operation \"../\" " << ans << " times and go back to the main folder." << endl;

    return 0;
}