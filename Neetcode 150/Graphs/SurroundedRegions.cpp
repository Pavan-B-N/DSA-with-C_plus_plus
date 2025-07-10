// https://leetcode.com/problems/surrounded-regions/description/

#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Top and bottom rows
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O' && !visited[0][j])
                dfs(board, visited, 0, j);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j])
                dfs(board, visited, m - 1, j);
        }

        // Left and right columns
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(board, visited, i, 0);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1])
                dfs(board, visited, i, n - 1);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited,
             int row, int col)
    {
        visited[row][col] = true;

        int rowNbr[] = {0, 0, -1, 1};
        int colNbr[] = {-1, 1, 0, 0};

        for (int k = 0; k < 4; k++)
        {
            int nr = row + rowNbr[k];
            int nc = col + colNbr[k];

            if (isSafe(board, visited, nr, nc))
            {
                dfs(board, visited, nr, nc);
            }
        }
    }

    bool isSafe(vector<vector<char>> &board, vector<vector<bool>> &visited,
                int row, int col)
    {
        int m = board.size();
        int n = board[0].size();
        return row >= 0 && row < m && col >= 0 && col < n &&
               !visited[row][col] && board[row][col] == 'O';
    }
};