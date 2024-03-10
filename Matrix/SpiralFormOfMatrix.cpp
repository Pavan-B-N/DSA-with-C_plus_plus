/*
{
    {1,2,3},
    {4,5,6},
    {7,8,9}
}

1,2,3,6,9,8,7,4,5
*/
#include <iostream>
#include <vector>
using namespace std;

void printSpiral(const vector<vector<int>>& matrix) {
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}


int main(){
    vector<vector<int>> matrix={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printSpiral(matrix);

    return 0;
}