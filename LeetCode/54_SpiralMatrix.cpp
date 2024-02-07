#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] << "  ";
}

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> answer;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col;
        int count = 0;

        int startRow = 0;
        int endCol = col - 1;
        int endRow = row - 1;
        int startCol = 0;

        while (count < total)
        {
            // Print starting row:
            for (int i = startCol; i <= endCol; i++)
            {
                if (count >= total)
                    break;
                answer.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            // Print ending column:
            for (int i = startRow; i <= endRow; i++)
            {
                if (count >= total)
                    break;
                answer.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            // Print ending row:
            for (int i = endCol; i >= startCol; i--)
            {
                if (count >= total)
                    break;
                answer.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            // Print starting column:
            for (int i = endRow; i >= startRow; i--)
            {
                if (count >= total)
                    break;
                answer.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return answer;
    }
};

int main()
{
    vector<vector<int>> matrix;
    matrix = {{1, 2, 3, 4},
              {5, 6, 7, 8},
              {9, 10, 11, 12}};

    Solution obj;
    vector<int> answer;
    answer = obj.spiralOrder(matrix);
    printVector(answer);

    return 0;
}