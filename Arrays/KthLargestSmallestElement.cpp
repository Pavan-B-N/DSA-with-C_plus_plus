/*
K’th Smallest/Largest Element in Unsorted Array

Given an array arr[] of size N and a number K, where K is smaller than the size of the array. Find the K’th smallest element in the given arra
Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3
Output: 7

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// o(nlogn)
int kthSmallest(vector<int> arr, int k)
{
    int n = arr.size();
    if (k >= n)
    {
        return -1;
    }
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

// https://leetcode.com/problems/kth-largest-element-in-an-array/
// other approaches includes priority queue and counting sort
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
    {
        return -1;
    }
    // time complexity for maxHeap operations is o(logn)
    // space complexity is o(n)
    priority_queue<int> maxHeap;
    for (int ele : nums)
    {
        maxHeap.push(ele);
    }

    int kthLargest = -1;
    while (!maxHeap.empty() && k > 0)
    {
        kthLargest = maxHeap.top();
        maxHeap.pop();
        k--;
    }

    return kthLargest;
}

int findKthSmallest(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
    {
        return -1;
    }

    // Time complexity for minHeap operations is O(log n)
    // Space complexity is O(n)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int ele : nums)
    {
        minHeap.push(ele);
    }

    int kthSmallest = -1;
    while (!minHeap.empty() && k > 0)
    {
        kthSmallest = minHeap.top();
        minHeap.pop();
        k--;
    }

    return kthSmallest;
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    cout << kthSmallest(arr, 3);
    return 0;
}