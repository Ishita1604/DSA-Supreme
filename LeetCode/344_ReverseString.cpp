#include <bits/stdc++.h>
using namespace std;

void print(vector<char> s)
{
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
}

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int start = 0, end = n - 1;
        while (start <= end)
        {
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    print(s);
    obj.reverseString(s);
    print(s);

    return 0;
}