#include <bits/stdc++.h>
using namespace std;

/*
We are given nP number of pratas and nC number of cooks with R as rank of each cook.
Cook of rank R cooks 1st prata in R minutes, 2nd in next 2R minutes, 3rd in next 3R minutes. And so on ...
Cook of rank 1 cooks in 1, 2, 3, 4, ... minutes.
Cook of rank 2 cooks in 2, 4, 6, 8, ... minutes.
Cook of rank 3 cooks in 3, 6, 9, 12, ... minutes.
Thus, time taken by cook of rank R to cook k pratas = R * (k*(k+1)/2) minutes.
Find the minimum time required to cook nP pratas. If cooks work simultaneously.

APPROACH:
Defined search space of time is [0, max_time] where max_time is time taken by cook of highest rank.
1. LINEAR SEARCH - Iterate over each time and find if nP pratas can completely be cooked. If yes, found answer.
2. BINARY SEARCH - Iterate and if in that time prata can be prepared, then store answer and search for lesser time in left. Else, search right.
*/

bool possibleSolution(vector<int> cookRanks, int mid, int nP)
{
    // Check if nP pratas can be cooked in mid number of minutes.
    int prata_counter = 0;
    for (int i = 0; i < cookRanks.size(); i++)
    {
        int R = cookRanks[i];
        int j = 1; // For incrementing to next prata for the same cook.
        int timeTaken = 0;

        while (true)
        {
            if (timeTaken + R * j <= mid)
            {
                prata_counter++;
                timeTaken += R * j;
                j++;
            }
            else
                break;
        }

        if (prata_counter >= nP)
            return true;
    }
    return false;
}

int minTimeToCompletePrataOrder(vector<int> cookRanks, int nP)
{
    int s = 0;
    int highest_rank = *max_element(cookRanks.begin(), cookRanks.end());
    int e = highest_rank * (nP * (nP + 1) / 2);
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (possibleSolution(cookRanks, mid, nP))
        {
            ans = mid;   // Store the answer.
            e = mid - 1; // Search left for minimum time.
        }
        else
            s = mid + 1; // Search right.
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int nP, nC;
        cin >> nP >> nC;
        vector<int> cookRanks;
        while (nC--)
        {
            int R;
            cin >> R;
            cookRanks.push_back(R);
        }
        cout << minTimeToCompletePrataOrder(cookRanks, nP);
    }

    return 0;
}