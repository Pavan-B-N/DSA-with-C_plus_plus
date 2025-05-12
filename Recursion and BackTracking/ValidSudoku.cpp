// https://leetcode.com/problems/valid-sudoku/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    if (!isValid(row, col, board, board[row][col]))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, vector<vector<char>> &board, char val)
    {
        for (int i = 0; i < 9; i++)
        {
            // check for the row
            if (col != i && board[row][i] == val)
                return false;

            // check for col
            if (row != i && board[i][col] == val)
                return false;

            // check for subBoard
            int subBoardRow = (row / 3) * 3 + i / 3;
            int subBoardCol = (col / 3) * 3 + i % 3;

            if ((row != subBoardRow || col != subBoardCol) && board[subBoardRow][subBoardCol] == val)
                return false;
        }
        return true;
    }
};