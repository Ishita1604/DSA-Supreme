#include <bits/stdc++.h>
using namespace std;

// Time:  O(N)
// Space: O(1)
bool threeConsecutiveOdds(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    int count = 0;
    while (i < n)
    {
        count = arr[i] % 2 ? count + 1 : 0;
        if (count == 3)
            return true;
        i++;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    bool isConsecutive = threeConsecutiveOdds(arr);
    if (isConsecutive)
        cout << "There are three consecutive odds." << endl;
    else
        cout << "There are no three consecutive odds." << endl;

    return 0;
}
