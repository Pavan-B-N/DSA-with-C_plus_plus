/*
https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/

#include <iostream>
#include <vector>
using namespace std;
void reverseArray(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    reverseArray(nums, 0, n - 1);
    reverseArray(nums, 0, k - 1);
    reverseArray(nums, k, n - 1);
}