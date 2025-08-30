// https://leetcode.com/problems/valid-sudoku/
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
                if (board[row][col] != '.' && !isValid(board, row, col))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board, int row, int col)
    {
        char symbol = board[row][col];

        // verify row and col together
        for (int i = 0; i < 9; i++)
        {
            // row
            if (col != i && board[row][i] == symbol)
            {
                return false;
            }

            // col
            if (row != i && board[i][col] == symbol)
            {
                return false;
            }

            // subBoard
            int subBoardRow = (row / 3) * 3 + i / 3;
            int subBoardCol = (col / 3) * 3 + i % 3;

            if (subBoardRow != row && subBoardCol != col && board[subBoardRow][subBoardCol] == symbol)
            {
                return false;
            }
        }
        return true;
    }
};