// https://leetcode.com/problems/sudoku-solver/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                // check for not filled cell
                if (board[row][col] == '.')
                {
                    // if the cell is not filled, try to fill the cell with the numbers 1-9
                    for (char val = '1'; val <= '9'; val++)
                    {
                        if (isValid(row, col, board, val))
                        {
                            board[row][col] = val;
                            // once we filled the value we need to check if we can fill the remaining once from this board
                            if (solve(board))
                            {
                                return true;
                            }

                            // we failed to fill the entire board based on previous decision so backtrack the changes
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        // none of the cells is empty
        return true;
    }

    bool isValid(int row, int col, vector<vector<char>> &board, char val)
    {
        for (int i = 0; i < 9; i++)
        {
            // check for the row
            if (board[row][i] == val)
                return false;

            // check for col
            if (board[i][col] == val)
                return false;

            // check for subBoard
            int subBoardRow = (row / 3) * 3;
            int subBoardCol = (col / 3) * 3;

            if (board[subBoardRow + i / 3][subBoardCol + i % 3] == val)
                return false;
        }
        return true;
    }
};