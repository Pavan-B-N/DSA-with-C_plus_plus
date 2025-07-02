// https://leetcode.com/problems/word-search/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == word[0])
                {
                    if (dfs(row, col, 0, board, word, visited))
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(int row, int col, int i, vector<vector<char>> &board, string word,
             vector<vector<bool>> &visited)
    {
        if (i == word.size() - 1)
            return true;

        visited[row][col] = true;

        int rowNbr[] = {-1, 0, 0, 1};
        int colNbr[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++)
        {
            int newRow = row + rowNbr[k], newCol = col + colNbr[k];
            if (isSafe(newRow, newCol, i + 1, board, word, visited))
            {
                if (dfs(newRow, newCol, i + 1, board, word, visited))
                    return true;
            }
        }

        visited[row][col] = false;
        return false;
    }

    bool isSafe(int row, int col, int i, vector<vector<char>> &board,
                string &word, vector<vector<bool>> &visited)
    {
        return row >= 0 && row < board.size() &&
               col >= 0 && col < board[0].size() &&
               !visited[row][col] && board[row][col] == word[i];
    }
};
