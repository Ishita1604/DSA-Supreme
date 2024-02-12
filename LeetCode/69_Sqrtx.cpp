#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;

        long long s = 0;
        long long e = x;
        long long m = s + (e - s) / 2;
        long long ans = -1;

        while (s <= e)
        {
            if (m * m == x)
                return m;
            else if (m * m > x) // Search left.
                e = m - 1;
            else // Store & search right.
            {
                // m * m < x
                ans = m;
                s = m + 1;
            }
            m = s + (e - s) / 2;
        }
        return ans;
    }
};

int main()
{
    int x = 10;
    Solution obj;
    int ans = obj.mySqrt(x);
    cout << ans << endl;

    return 0;
}