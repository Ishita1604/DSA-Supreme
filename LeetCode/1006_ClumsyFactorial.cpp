#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int clumsy(int n)
    {
        // 10!
        // 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1 = 12
    
        // In 1st:    * by next.
        // In 2nd:    / by next.
        // In 3rd:    + by next.
        // In 4th:    - by next.
        int count = 0;
        stack<int> s;
        s.push(n);

        for (int i = n - 1; i > 0; i--)
        {
            count++;
            if (count % 4 == 1)
            {
                // MULTIPLY:
                int x = s.top();
                s.pop();
                int y = x * i;
                s.push(y);
            }
            if (count % 4 == 2)
            {
                // DIVISION:
                int x = s.top();
                s.pop();
                int y = x / i;
                s.push(y);
            }
            if (count % 4 == 3)
            {
                // ADD:
                s.push(i);
            }
            if (count % 4 == 0)
            {
                // SUBTRACT:
                int y = (-1) * i;
                s.push(y);
            }
        }

        int answer = 0;
        while (!s.empty()) // We have to add these numbers.
        {
            int x = s.top();
            answer = answer + x;
            s.pop();
        }

        return answer;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.clumsy(n);

    return 0;
}