#include <bits/stdc++.h>
using namespace std;

// Time: O(log(numBottles) / log(numExchange))
// Space: O(1)
int numWaterBottles(int numBottles, int numExchange)
{
    int drink = 0; // Number of bottles drunk.
    int empty = 0; // Number of bottles emptied.

    while (numBottles > 0) // Loop will run as long as we have full bottles.
    {
        drink += numBottles;              // These all will be drunk initially.
        empty += numBottles;              // And after drunk, these get empty.
        numBottles = empty / numExchange; // New number of full bottles obtained after exchanging them with empty ones.
        empty = empty % numExchange;      // Update empty bottles.
    }
    return drink;
}

int main()
{
    int numBottles = 9;
    int numExchange = 3;
    int ans = numWaterBottles(numBottles, numExchange);
    cout << "Number of water bottles you can drink: " << ans << endl;
    return 0;
}
