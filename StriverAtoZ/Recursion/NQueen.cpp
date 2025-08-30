// https://leetcode.com/problems/n-queens/
/*
left[row]=1;
leftLowerDiagonal[row+col]=1;
leftUpperDiagonal[n-1+col-row]=1;
*/
#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity
Best case (solution found at 1st pass)	O(N²)
Worst case	O(N! * N)
*/
/*
Space Complexity
S = total number of solutions (varies per N)
N^2 = space to store each board
Recursion stack	O(N)

O(S · N^2)
*/
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string rowInBoard(n, '.');
        for (int i = 0; i < n; i++)
        {
            // by default no queens are placed
            board[i] = rowInBoard;
        }

        solve(0, board, ans, n);

        return ans;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        // out of 8 directions
        // top and down is not required as we are visiting each column exactly onec
        // right, right top diagonal and right bottom diagonal also not required as we haven't visited tehm yet
        // so we just need to check 3 directions out of 8
        // left, left top diagonal, left bottom diagonal
        int actualRow = row;
        int actualCol = col;

        // left top diagonal (row--,col--)
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                // queen attacks
                return false;
            }
            row--;
            col--;
        }

        row = actualRow;
        col = actualCol;
        // left (row, col--)
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                // queen attacks
                return false;
            }
            col--;
        }

        row = actualRow;
        col = actualCol;
        // left botoom diagonal(row++,col--)
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                // queen attacks
                return false;
            }
            row++;
            col--;
        }

        return true;
    }
};

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string rowInBoard(n, '.');
        for (int i = 0; i < n; i++)
        {
            // by default no queens are placed
            board[i] = rowInBoard;
        }

        // cache method to store if there is a queen in left, leftUpperDiagonal, leftLowerDiagonal
        vector<int> left(n, 0), leftUpperDiagonal(2 * n - 1, 0), leftLowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans, n, left, leftUpperDiagonal, leftLowerDiagonal);

        return ans;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n,
               vector<int> &left, vector<int> &leftUpperDiagonal, vector<int> &leftLowerDiagonal)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, left, leftUpperDiagonal, leftLowerDiagonal))
            {
                board[row][col] = 'Q';
                left[row] = 1;
                leftLowerDiagonal[row + col] = 1;
                leftUpperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, n, left, leftUpperDiagonal, leftLowerDiagonal);
                board[row][col] = '.';
                left[row] = 0;
                leftLowerDiagonal[row + col] = 0;
                leftUpperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    bool isSafe(int row, int col, int n,
                vector<int> &left, vector<int> &leftUpperDiagonal, vector<int> &leftLowerDiagonal)
    {
        // 0 indicates that no one occupaied
        return left[row] == 0 && leftUpperDiagonal[n - 1 + col - row] == 0 && leftLowerDiagonal[row + col] == 0;
    }
};