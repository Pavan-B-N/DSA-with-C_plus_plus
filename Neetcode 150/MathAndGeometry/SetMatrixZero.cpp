// https://leetcode.com/problems/set-matrix-zeroes/
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        // Check if first row needs to be zero
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        // Check if first column needs to be zero
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        // Use first row and column to mark zero rows/cols
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;// mark row
                    matrix[0][j] = 0;// mark col
                }
            }
        }

        // Zero cells based on markers
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero first row if needed
        if (isFirstRowZero) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero first column if needed
        if (isFirstColZero) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
