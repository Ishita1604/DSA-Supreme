#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> v, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n - 1;
        int m = (s + e) / 2;
        int ans = -1;

        while (s <= e)
        {
            if (v[m] == target)
            {
                ans = m;
                e = m - 1;
            }
            else if (target > v[m])
                s = m + 1;
            else
                e = m - 1;

            m = (s + e) / 2;
        }
        return ans;
    }
}

int lastOcc(vector<int> v, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n - 1;
        int m = (s + e) / 2;
        int ans = -1;

        while (s <= e)
        {
            if (v[m] == target)
            {
                ans = m;
                s = m + 1;
            }
            else if (target > v[m])
                s = m + 1;
            else
                e = m - 1;

            m = (s + e) / 2;
        }
        return ans;
    }
}

int main()
{
    vector<int> v = {1, 2, 2, 3, 44, 60, 67, 67, 67, 89};
    int n = v.size();
    int target = 67;

    int first = firstOcc(v, n, target);
    // cout << first;

    int last = lastOcc(v, n, target);
    // cout << last;

    int total_occ = last - first + 1;
    cout << "Total occurrence are: " << total_occ;

    return 0;
}