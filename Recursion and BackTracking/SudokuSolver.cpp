/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void display(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    int n = board.size();
    // Check the row
    for (int i = 0; i < n; ++i) {
        if (board[row][i] == num) {
            return false;
        }
    }
    
    // Check the column
    for (int i = 0; i < n; ++i) {
        if (board[i][col] == num) {
            return false;
        }
    }
    
    // Check the subgrid
    int sqrtN = sqrt(n);
    int startRow = row - row % sqrtN;
    int startCol = col - col % sqrtN;
    for (int i = 0; i < sqrtN; ++i) {
        for (int j = 0; j < sqrtN; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    int n = board.size();
    int row = -1, col = -1;

    // Find an empty cell
    bool emptyLeft = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                emptyLeft = true;
                break;
            }
        }
        if (emptyLeft) {
            break;
        }
    }

    // If there are no empty cells left, puzzle is solved
    if (!emptyLeft) {
        return true;
    }

    // Backtrack
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solve(board)) {
                return true;
            }
            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    vector<vector<int>> board = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solve(board)) {
        display(board);
    } else {
        cout << "Cannot solve" << endl;
    }

    return 0;
}
