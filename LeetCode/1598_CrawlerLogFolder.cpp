#include <bits/stdc++.h>
using namespace std;

// Time: O(N)
// Space: O(1)
int minOperations(vector<string> &logs)
{
    int count = 0;
    for (int i = 0; i < logs.size(); i++)
    {
        if (logs[i] == "../" && (count > 0))
            count--;
        else if (logs[i] == "./")
            continue;
        else
            count++;
    }
    return count;
}

int main()
{
    vector<string> logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    int ans = minOperations(logs);
    cout << "Use the change folder operation \"../\" " << ans << " times and go back to the main folder." << endl;
    return 0;
}