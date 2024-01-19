// Best Time to Buy and Sell Stock (Level 1)
// Greedy Approach: Buy at minimum, sell at maximum.

/** APPROACH:

 * Buy has to be done before sell.
 * 1. For every element in `price`, is this cheaper than last one?
 * 2. If cheaper, does it yield a greater profit than last one?
 * If (1) is false, no need to check for (2).

**/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int max_price = INT_MIN;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i]; // Update `min_price`.
                for (int j = i + 1; j < prices.size(); j++)
                {
                    max_price = prices[j];
                    if ((max_price - min_price) > profit)
                        profit = max_price - min_price;
                }
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = {7, 15, 3, 6, 4, 1, 10};

    Solution obj1;
    int answer = obj1.maxProfit(prices);
    cout << answer;

    return 0;
}
