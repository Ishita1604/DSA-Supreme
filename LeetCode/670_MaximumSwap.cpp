#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Greedy Approach: Try placing the largest digit from the right at the MSB at left.
    // TIME: O(N)
    // SPACE: O(N)
    int maximumSwap(int num)
    {
        // Convert given number to string for index-based accessing.
        string s = to_string(num);
        int n = s.length();
        vector<int> maxRight(n);
        maxRight[n - 1] = n - 1;

        // Mapping right-most maximum element of string's each element.
        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] <= s[maxRight[i + 1]]) maxRight[i] = maxRight[i + 1];
            else maxRight[i] = i;
        } // Vector "maxRight" is prepared.

        // Now the highest number has to be placed at MSB.
        for (int i = 0; i < n; i++)
        {
            if (s[i] < s[maxRight[i]])
            {
                swap(s[i], s[maxRight[i]]);
                return stoi(s);
            }
        }
        return num;
    }
};

int main()
{
    int num = 1993;
    Solution obj;
    cout << "Maximum number formed after one swap is " << obj.maximumSwap(num) << endl;

    return 0;
}