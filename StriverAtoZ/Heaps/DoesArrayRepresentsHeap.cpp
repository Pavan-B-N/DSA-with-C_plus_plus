// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
/*
Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

Example 1:

Input:
n = 6
arr[] = {90, 15, 10, 7, 12, 2}
Output:
1
Explanation:
The given array represents below tree
       90
     /    \
   15      10
  /  \     /
7    12  2
The tree follows max-heap property as every
node is greater than all of its descendants.
*/

// Binary Heap
class Solution
{
public:
    //   0-based index array representation of a binary heap:
    // The left child of node at index i is at 2*i + 1.
    // The right child is at 2*i + 2.
    //   The last internal node is at index floor(n/2) - 1.

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i <= (n / 2) - 1; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[i] < arr[left])
                return false;
            if (right < n && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};
