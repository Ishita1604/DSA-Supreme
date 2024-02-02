#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (count > 0)
                    return count;
                continue;
            }
            else
                count++;
        }
        return count;
    }
};

int main()
{
    string s = "   Fly me      to  the  moon    ";
    Solution obj;
    cout << "Length of Last Word: " << obj.lengthOfLastWord(s);

    return 0;
}
