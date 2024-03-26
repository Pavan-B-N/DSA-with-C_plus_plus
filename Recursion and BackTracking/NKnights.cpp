#include <iostream>
#include <vector>
using namespace std;

void display(const vector<vector<bool>>& board) {
    for (const auto& row : board) {
        for (bool element : row) {
            if (element) {
                cout << "K ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

bool isValid(const vector<vector<bool>>& board, int row, int col) {
    int n = board.size();
    return row >= 0 && row < n && col >= 0 && col < n;
}

bool isSafe(const vector<vector<bool>>& board, int row, int col) {
    static const vector<pair<int, int>> moves = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}};
    for (const auto& move : moves) {
        int newRow = row + move.first;
        int newCol = col + move.second;
        if (isValid(board, newRow, newCol) && board[newRow][newCol]) {
            return false;
        }
    }
    return true;
}

void knight(vector<vector<bool>>& board, int row, int col, int knights) {
    int n = board.size();
    if (knights == 0) {
        display(board);
        cout << endl;
        return;
    }
    
    if (row == n - 1 && col == n) {
        return;
    }
    
    if (col == n) {
        knight(board, row + 1, 0, knights);
        return;
    }
    
    if (isSafe(board, row, col)) {
        board[row][col] = true;
        knight(board, row, col + 1, knights - 1);
        board[row][col] = false;
    }
    
    knight(board, row, col + 1, knights);
}

int main() {
    int n = 4; // Size of the chessboard
    vector<vector<bool>> board(n, vector<bool>(n, false)); // Create the chessboard
    knight(board, 0, 0, 4); // Start the backtracking algorithm
    return 0;
}
