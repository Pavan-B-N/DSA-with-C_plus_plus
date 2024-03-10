/*
{ {1, 5, 9},
{14, 20, 21},
{30, 34, 43} }
*/
#include <iostream>
#include <vector>

using namespace std;


//The time complexity of the given program, which searches for an element in a sorted matrix, is O(m + n), where 'm' is the number of rows in the matrix and 'n' is the number of columns.
//O(m + n)
bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false; // Empty matrix
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // Element found
        } else if (matrix[row][col] < target) {
            row++; // Move down in the matrix
        } else {
            col--; // Move left in the matrix
        }
    }

    return false; // Element not found
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 9;

    if (searchMatrix(matrix, target)) {
        cout << "Element " << target << " is present in the matrix.\n";
    } else {
        cout << "Element " << target << " is not present in the matrix.\n";
    }

    return 0;
}
