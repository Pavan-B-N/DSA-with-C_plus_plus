/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9

Input: K = 3, N = 4, arr = { {1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}}
Output: 0 1 2 3 4 5 6 7 8 9 10 11 

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ArrayElement {
    int value;
    int arrayIndex;
    int elementIndex;

    // Overloading the '<' operator for min-heap comparison
    bool operator<(const ArrayElement& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    vector<int> result;
    priority_queue<ArrayElement> minHeap;

    // Initialize the heap with the first element from each array
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    while (!minHeap.empty()) {
        ArrayElement current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);

        // Move to the next element in the same array
        int nextElementIndex = current.elementIndex + 1;
        if (nextElementIndex < arrays[current.arrayIndex].size()) {
            minHeap.push({arrays[current.arrayIndex][nextElementIndex], current.arrayIndex, nextElementIndex});
        }
    }

    return result;
}

int main() {
    vector<vector<int>> arrays = {{1, 3, 5}, {2, 4, 6}, {0, 7, 8, 9}};
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Print the merged array
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
