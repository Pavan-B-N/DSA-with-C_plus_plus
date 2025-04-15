/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/
442. Find All Duplicates in an Array
Solved
Medium
Topics
Companies
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    //cyclic sort
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> result;
            
            for (int i = 0; i < nums.size(); ++i) {
                int index = abs(nums[i]) - 1; // Find the index corresponding to the value
                
                if (nums[index] < 0) {
                    // If already negative, it means we've seen this number
                    result.push_back(abs(nums[i]));
                } else {
                    // Mark as visited by negating
                    nums[index] = -nums[index];
                }
            }
            
            return result;
        }
    };
    