#include <bits/stdc++.h>
using namespace std;

/********* LeetCode 2022/; Convert 1D Array Into 2D Array *********/
// Link: [https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01]


// Time: O(m * n) as while loop runs m times, processing n elements in each iteration.
// Space: O(m * n) for the 2D vector created.
vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
    if (original.size() != m * n) // Matrix creation impossible.
        return {};

    vector<vector<int>> newArr;
    int el = 0;
    while (el != original.size())
    {
        vector<int> row;
        for (int i = 0; i < n; i++)
            row.push_back(original[el++]);
        newArr.push_back(row);
    }
    return newArr;
}


int main()
{
    vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8};
    int m = 2, n = 4;

    vector<vector<int>> result = construct2DArray(original, m, n);
    for (const auto &row : result)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}