#include <bits/stdc++.h>
using namespace std;

int findSqrtx(int n)
{
    int s = 0;
    int e = n;
    int m = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (m * m == n)
            return m;
        else if (m * m < n)
        {
            // Store & search right:
            ans = m;
            s = m + 1;
        }
        else
            e = m - 1; // Search in left.
        m = s + (e - s) / 2;
    }
    return ans;
}

double sqrtxWithPrecision(int n, int precision)
{
    double final_ans = findSqrtx(n);
    double step = 0.1;
    for (int i = 0; i < precision; i++)
    {
        for (double j = final_ans; j * j <= n; j = j + step)
            final_ans = j; // Store and continue.
        step = step / 10;
    }
    return final_ans;
}

int main()
{
    int n, precision;
    cout << "Enter a Number: ";
    cin >> n;
    cout << "Enter the Precision Digit till which you want to calculate Square Root: ";
    cin >> precision;
    // Code works till 5-digit precision because of range of `double`.

    int ans = findSqrtx(n);
    cout << "Answer in Whole Number: " << ans << endl;

    double final_ans = sqrtxWithPrecision(n, precision);
    cout << "Final Answer is: " << final_ans << endl;

    return 0;
}