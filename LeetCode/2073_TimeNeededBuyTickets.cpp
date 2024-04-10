#include <bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int i = 0; // Index to iterate the vector.
    int t = 0;
    while (tickets[k] != 0) // Until all tickets have been bought by the person k.
    {
        if (i == tickets.size())
            i = 0; // Reset i to 0 that is front of the vector.
        if (tickets[i] != 0 && i < tickets.size())
        {
            tickets[i]--;
            t++;
            i++;
        }
        else
            i++;
    }
    return t;
}

int main()
{
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    int ans = timeRequiredToBuy(tickets, k);
    cout << ans;
    return 0;
}