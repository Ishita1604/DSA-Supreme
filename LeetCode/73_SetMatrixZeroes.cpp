#include <bits/stdc++.h>
using namespace std;

// Brute force approach for when elements are non-negative.
// If already -1 is present then it fails.
// TIME: O((NM) * (N + M)) + O(NM)
// SPACE: O(1)
class Solution
{
public:
    void markRow(vector<vector<int>> &matrix, int row, int col, int c)
    {
        // This function wants the column `c`.
        for (int i = 0; i < row; i++)
        {
            // Mark only non-zero as -1 so that the original 0 retains.
            if (matrix[i][c] != 0)
            {
                matrix[i][c] = -1;
            }
        }
    }

    void markCol(vector<vector<int>> &matrix, int row, int col, int r)
    {
        // This function wants the row `r`.
        for (int j = 0; j < col; j++)
        {
            if (matrix[r][j] != 0)
            {
                matrix[r][j] = -1;
            }
        }
    }

    void markBoth(vector<vector<int>> &matrix, int row, int col)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                // Send only that row and column that has element == 0:
                if (matrix[r][c] == 0)
                {
                    markRow(matrix, row, col, c); // O(row)
                    markCol(matrix, row, col, r); // O(col)
                }
            }
        }
    }

    vector<vector<int>> setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        markBoth(matrix, row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
        return matrix;
    }
};



// Better approach where we mark the index of that element and not the element.
// Two extra arrays created.
// TIME: O(2 * NM)
// SPACE: O(N) + O(M)
class Solution2
{
public:
    void markIndex(vector<vector<int>> &matrix, int row, int col, vector<int> &rowArr, vector<int> &colArr)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowArr[i] = 1;
                    colArr[j] = 1;
                }
            }
        }
    }

    void setIndex(vector<vector<int>> &matrix, int row, int col, vector<int> &rowArr, vector<int> &colArr)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (rowArr[i] || colArr[j]) // Found the indices to mark from 1 to 0.
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    vector<vector<int>> setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rowArr(row, 0); // Row array.
        vector<int> colArr(col, 0); // Column array.

        // Traverse the array for 0 and set the row and column array's index to 1.
        markIndex(matrix, row, col, rowArr, colArr);

        // Traverse array again and set the elements of marked indices to 0.
        setIndex(matrix, row, col, rowArr, colArr);

        return matrix;
    }
};

// Optimal approach because setting the 0's inplaceand no extra space.
// TIME: O(2 * NM)
// SPACE: O(1)
class Solution3
{
public:
    vector<vector<int>> setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        // No need to create the extra row and column arrays.
        int col0 = 1; // Initialized to 1 and we will see later if it gets marked to 0.

        // Traverse the entire matrix normally and mark corresponding inplace row and column to 0.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Mark the inplace row:
                    matrix[i][0] = 0;
                    // Mark the inplace column and variable `col0`:
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // Traverse matrix excluding inplace row and column and mark elements to 0.
        // Loops start from 1 so as to exclude.
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }


        // Finally mark the inplace row and column.
        // FIRST MARK INPLACE COLUMN THEN MARK INPLACE ROW!!
        // As inplace column is dependent on inplace row.
        // Column's edge element's value depends on matrix[0][0] which belongs to inplace row!!

        // Mark inplace column:
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
        }

        // Mark inplace row:
        if (col0 == 0)
        {
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }

        return matrix;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // vector<vector<int>> matrix = {{0, 1}};

    // Solution obj;
    // vector<vector<int>> ans = obj.setZeroes(matrix);
    // Print the output:
    // for (auto x : ans)
    // {
    //     for (auto y : x)
    //         cout << y << "  ";
    //     cout << endl;
    // }



    // Solution2 obj2;
    // vector<vector<int>> ans2 = obj2.setZeroes(matrix);
    // for (auto x : ans2)
    // {
    //     for (auto y : x)
    //         cout << y << "  ";
    //     cout << endl;
    // }


    Solution3 obj3;
    vector<vector<int>> ans3 = obj3.setZeroes(matrix);

    for (auto x : ans3)
    {
        for (auto y : x)
            cout << y << "  ";
        cout << endl;
    }

    return 0;
}