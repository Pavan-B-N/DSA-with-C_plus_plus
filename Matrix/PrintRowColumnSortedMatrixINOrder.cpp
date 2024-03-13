/*
Print all elements in sorted order from row and column wise sorted matrix
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of the matrix in sorted order.

Input: mat[][] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                   };
Output: 10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50

*/

/*
The solution utilizes a min-heap data structure
Time Complexity:
1.Building the Heap: O(N * log(N)) 
2.Popping Elements from Heap: In the worst case, we might have to pop all elements from the heap, which takes O(N * M * log(N)) time, where M is the number of columns


So, the overall time complexity of the program is O(N * M * log(N)), where N is the number of rows and M is the number of columns.

Time complexity: O(N * M * log(N))
Space complexity: O(N * M)
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define a class to store elements of the matrix with their row and column indices
class MatrixElement {
public:
    int value;
    int row;
    int col;

    // Constructor
    MatrixElement(int v, int r, int c) : value(v), row(r), col(c) {}

    // Overloading '<' operator for comparison in the min-heap
    bool operator<(const MatrixElement& other) const {
        return value > other.value; // Elements are compared based on their values
    }
};

// Function to print elements of matrix in sorted order
void printSorted(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    // Create a min-heap of MatrixElement type
    priority_queue<MatrixElement> minHeap;

    // Push the first column elements into the min-heap along with their indices
    for (int i = 0; i < rows; ++i) {
        minHeap.push(MatrixElement(mat[i][0], i, 0));
    }

    // Loop until min-heap is empty
    while (!minHeap.empty()) {
        // Pop the smallest element from the min-heap
        MatrixElement current = minHeap.top();
        minHeap.pop();

        // Print the current element
        cout << current.value << " ";

        // If there's a next element in the same row, push it into the min-heap
        if (current.col + 1 < cols) {
            minHeap.push(MatrixElement(mat[current.row][current.col + 1], current.row, current.col + 1));
        }
    }
}

// Example usage
int main() {
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                   {15, 25, 35, 45},
                                   {27, 29, 37, 48},
                                   {32, 33, 39, 50}};
    cout << "Sorted elements of the matrix: ";
    printSorted(matrix);
    cout << endl;
    return 0;
}
/*
If you use a Binary Search Tree (BST) instead of a min-heap,
1.Building the BST:O(N * log(N)) 
2.In-order Traversal of BST:Performing an in-order traversal of the BST yields the elements in sorted order. In the worst case, traversing the entire BST takes O(N) time.

So, the overall time complexity for building the BST and traversing it is O(N * log(N)) + O(N) = O(N * log(N)).


Time complexity: O(N * log(N))
Space complexity: O(N * M)
*/
