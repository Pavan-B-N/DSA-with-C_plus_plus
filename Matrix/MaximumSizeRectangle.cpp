/*
Maximum size rectangle binary sub-matrix with all 1s
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :
8
Explanation : 
The largest rectangle with only 1's is from 
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1

Input:
0 1 1
1 1 1
0 1 1      
Output:
6
Explanation : 
The largest rectangle with only 1's is from 
(0, 1) to (2, 2) which is
1 1
1 1
1 1
*/
// Dynamic programming problem
/*
The solution employs a dynamic programming approach to calculate the maximum size rectangle for each row. It then utilizes the "largest rectangle in a histogram" problem to find the maximum size rectangle in the entire matrix.
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find the maximum area rectangle in a histogram
int maxHistArea(vector<int>& hist) {
    stack<int> s;
    int maxArea = 0;
    int tp;
    int areaWithTop;
    int i = 0;
    while (i < hist.size()) {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else {
            tp = s.top();
            s.pop();
            areaWithTop = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, areaWithTop);
        }
    }
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        areaWithTop = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        maxArea = max(maxArea, areaWithTop);
    }
    return maxArea;
}

// Function to find the maximum size rectangle binary sub-matrix with all 1s
int maxRectangle(vector<vector<int>>& matrix) {
    int maxArea = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> hist(cols, 0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0)
                hist[j] = 0;
            else
                hist[j] += 1;
        }
        maxArea = max(maxArea, maxHistArea(hist));
    }
    return maxArea;
}

// Example usage
int main() {
    vector<vector<int>> matrix = {{0, 1, 1, 0},
                                   {1, 1, 1, 1},
                                   {1, 1, 1, 1},
                                   {1, 1, 0, 0}};
    cout << "Maximum size rectangle binary sub-matrix with all 1s: " << maxRectangle(matrix) << endl;
    return 0;
}
