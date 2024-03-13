/*
https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array/

Kth smallest element in a row-wise and column-wise sorted 2D array

Given an n x n matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the given 2D array

Input:k = 3 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50 
Output: 20
Explanation: The 3rd smallest element is 20 

Input:k = 7 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50 
Output: 30
Explanation: The 7th smallest element is 30
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Custom comparator for min heap
class Compare {
public:
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) const {
        return a.first > b.first;
    }
};
/*
Heap approach: best one 

Time Complexity: O(N * log(N) + K * log(N)), where N is the number of rows/columns in the matrix and K is the value of k.
Space Complexity: O(N).
*/
int kthSmallestHeap(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> minHeap;

    // Insert the first element of each row into the min heap
    for (int i = 0; i < n; ++i) {
        minHeap.push({matrix[i][0], {i, 0}});
    }

    // Extract the kth smallest element by popping from the heap k-1 times
    for (int i = 0; i < k - 1; ++i) {
        auto top = minHeap.top();
        minHeap.pop();
        int row = top.second.first;
        int col = top.second.second;
        if (col < n - 1) {
            minHeap.push({matrix[row][col + 1], {row, col + 1}});
        }
    }

    // Return the kth smallest element
    return minHeap.top().first;
}

/*
Pointer Approach:

Time Complexity: O(N * log(H - L)), where H is the maximum element and L is the minimum element in the matrix.
Space Complexity: O(1).
*/
int kthSmallestPointer(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        int j = n - 1;
        for (int i = 0; i < n; ++i) {
            while (j >= 0 && matrix[i][j] > mid) {
                j--;
            }
            count += (j + 1);
        }
        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {{1, 5, 9},
                                   {10, 11, 13},
                                   {12, 13, 15}};
    int k = 8;
    cout << "Kth smallest element using heap approach: " << kthSmallestHeap(matrix, k) << endl;
    cout << "Kth smallest element using heap approach: " << kthSmallestPointer(matrix, k) << endl;
    return 0;
}

