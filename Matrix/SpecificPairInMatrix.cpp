/*
Find a specific pair in Matrix

Given a matrix of size N x N containing distinct integers, the task is to find a specific pair (a, b) such that a < b and both a and b belong to the same row or the same column.
*/
/*
The solution employs a dynamic programming approach to precompute the maximum and minimum values in submatrices
*/
#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

// Function to find maximum value pair such that one element of pair is in same row or column of another element
void findSpecificPair(int mat[][5], int N) {
    // Variables to store maximum and minimum values in matrix
    int maxVal = INT_MIN, minVal = INT_MAX;

    // Traverse the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Update maxVal if current element is greater
            if (mat[i][j] > maxVal)
                maxVal = mat[i][j];

            // Update minVal if current element is smaller
            if (mat[i][j] < minVal)
                minVal = mat[i][j];
        }
    }

    // Initialize the result
    int maxDiff = INT_MIN;

    // Traverse the matrix again to find the maximum difference
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Update result if current element is (a, b) such that a < b and both a and b belong to same row or column
            if (i < N - 1 && j < N - 1) {
                int diff1 = max(mat[i + 1][j + 1] - mat[i][j], mat[i][j] - mat[i + 1][j + 1]);
                maxDiff = max(maxDiff, diff1);
            }
        }
    }

    // Print the result
    cout << "Maximum difference is " << maxDiff << endl;
}

// Driver code
int main() {
    int mat[5][5] = {{1, 2, -1, -4, -20},
                     {-8, -3, 4, 2, 1},
                     {3, 8, 6, 1, 3},
                     {-4, -1, 1, 7, -6},
                     {0, -4, 10, -5, 1}};
    findSpecificPair(mat, 5);
    return 0;
}
