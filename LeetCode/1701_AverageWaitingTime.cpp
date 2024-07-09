#include <bits/stdc++.h>
using namespace std;

// Time: O(N)
// Space: O(1)
double averageWaitingTime(vector<vector<int>> &customers)
{
    int free = 0;  // When cooking is completed for that customer.
    double wt = 0; // Total waiting time.

    for (int i = 0; i < customers.size(); i++)
    {
        if (free < customers[i][0])
        {
            // Start cooking immediately.
            free = customers[i][0] + customers[i][1];
            wt += customers[i][1];
        }
        else
        {
            // Customer must wait for his turn.
            wt += (free + customers[i][1]) - customers[i][0];
            free = free + customers[i][1];
        }
    }
    return (wt / customers.size());
}

int main()
{
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
    double ans = averageWaitingTime(customers);
    cout << "The average waiting time is: " << ans << endl;
    return 0;
}
