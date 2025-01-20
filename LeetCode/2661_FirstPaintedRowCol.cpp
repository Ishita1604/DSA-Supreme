#include <bits/stdc++.h>
using namespace std;


/* _________________________________________________________________________________________
LeetCode 2661: First Completely Painted Row or Column
Link: [https://leetcode.com/problems/bitwise-xor-of-all-pairings/]

You are given a 0-indexed integer array arr, and an m x n integer matrix mat.
Both arr and mat contain all the integers in the range [1, m * n].
Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
Return the smallest index i at which either a row or a column will be completely painted in mat.
 

Example 1:
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

Example 2:
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].

_____________________________________________________________________________________________
*/


class Solution
{
public:
    // TIME: O(M*N) to traverse matrix M*N and array arr of M*N elements.
    // SPACE: O(M*N) for rowPosition, colPosition and O(M+N) for count hashmaps. Overall O(M*N).
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        // Step 1: Pre-process matrix element's positions in hash map.
        unordered_map<int, int> rowPosition, colPosition, rowCount, colCount;
        int m = mat.size();    // # of rows.
        int n = mat[0].size(); // # of columns.
        // Traverse matrix and store its positions.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowPosition[mat[i][j]] = i;
                colPosition[mat[i][j]] = j;
            }
        }
        // Step 2: Maintain rowCount, colCount to store frequency of visited rows & columns.
        // Increment that element's particular row & column frequency to mark visited.
        for (int i = 0; i < arr.size(); i++)
        {
            int el = arr[i];
            rowCount[rowPosition[el]]++;
            colCount[colPosition[el]]++;
            // Step 3: Check if incremented frequency became equal to m or n then return.
            if (rowCount[rowPosition[el]] == n || colCount[colPosition[el]] == m) return i;
        }
        return -1;
    }
};


int main()
{
    Solution obj;
    vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    cout << obj.firstCompleteIndex(arr, mat) << endl;

    return 0;
}