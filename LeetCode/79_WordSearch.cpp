#include <bits/stdc++.h>
using namespace std;

// Time: O(m * n * 4 ^ K)
// 4 ^ K because in worst case, all 4 top, left, right and bottom checked and repeated for length of word times.
// Space: O(K) as backtracking requires stack, and depth of stack equals the length of the word i.e. K.


bool isAdjacent(vector<vector<char>> &board, string word, int i, int j, int index, int m, int n) // Check adjacent indices.
{
    if (index == word.length()) // It means entire word has been found.
        return true;

    // All the false conditions:
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index] || board[i][j] == '#')
        return false;

    // Prevent reusing the same character:
    char c = board[i][j]; // First storing the character in `c`.
    board[i][j] = '#';    // Then marking that character as visited.

    // Backtracking is an approach where we explore different paths.
    // Once we reach dead end of last choice, we go back to the previous choice, and explore a different route from there.

    bool top = isAdjacent(board, word, i - 1, j, index + 1, m, n);    // Check top.
    bool right = isAdjacent(board, word, i, j - 1, index + 1, m, n);  // Check right.
    bool left = isAdjacent(board, word, i, j + 1, index + 1, m, n);   // Check left.
    bool bottom = isAdjacent(board, word, i + 1, j, index + 1, m, n); // Check bottom.

    // Restore that character in the board.
    board[i][j] = c;
    return top || right || left || bottom;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    int ch = 0;
    char first_letter = word[ch];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == first_letter) // Letter found and start matching from word's first character.
            {
                if (isAdjacent(board, word, i, j, ch, m, n))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";
    bool res = exist(board, word);
    if (res == 1)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}