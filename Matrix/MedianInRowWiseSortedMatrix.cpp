/*
We are given a row-wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.

Input:
1 3 5
2 6 9
3 6 9
Output:
Median is 5
If we put all the values in a sorted array A[] = 1 2 3 3 5 6 6 9 9)

*/

// difficult
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100;

// Function to find the count of elements less than or equal to target in a sorted vector
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}
// important
// Function to find median in the matrix
int binaryMedian(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < rows; i++) {
        // Finding the minimum element
        if (matrix[i][0] < min)
            min = matrix[i][0];

        // Finding the maximum element
        if (matrix[i][cols - 1] > max)
            max = matrix[i][cols - 1];
    }

    int desired = (rows * cols + 1) / 2;

    while (min < max) {
        int mid = min + (max - min) / 2;
        int count = 0;//count represents the space less than mid

        // Find count of elements smaller than or equal to mid using binary search
        for (int i = 0; i < rows; ++i)
            count += binarySearch(matrix[i], mid);

        if (count < desired)
            min = mid + 1;
        else
            max = mid;
    }

    return min;
}

// Driver program to check above functions
int main() {
    int r = 3, c = 3;
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << "Median is " << binaryMedian(matrix) << endl;

    return 0;
}
