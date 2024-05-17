#include <bits/stdc++.h>
using namespace std;

/* We are given N trees, and we have to cut a height of H metres from each tree.
Find maximum height of H such that the wood obtained after cutting is at-least M metres.

APPROACH:
1. LINEAR SEARCH - Iterate [0, height of tallest tree] and check for each value of H. Time: O(N) where N is height of tallest tree.
1. BINARY SEARCH - Time: O(N*logN) where N is height of tallest tree.
*/

bool possibleSolution(long long int mid, vector<long long int> trees, long long int M)
{
    long long int wood_cut = 0;
    long long int total_wood = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        {
            wood_cut = trees[i] - mid;
            total_wood += wood_cut;
        }
    }
    if (total_wood >= M)
        return true;
    return false;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int M)
{
    long long int s = 0;
    long long int e = *max_element(trees.begin(), trees.end()); // Height of the tallest tree.
    long long int ans = -1;

    while (s <= e)
    {
        long long int mid = e + (s - e) / 2;
        if (possibleSolution(mid, trees, M))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    // Input takes 2 integers N, number of trees, and M, amount of wood needed.
    // 2nd line contains height of each tree.
    cout << "Enter the values:" << endl;
    long long int N, M;
    vector<long long int> trees;
    cin >> N >> M;
    while (N--)
    {
        long long int treeHeight;
        cin >> treeHeight;
        trees.push_back(treeHeight);
    }
    cout << "Height to be cut from each tree is: " << maxSawBladeHeight(trees, M) << " metres!";
    return 0;
}