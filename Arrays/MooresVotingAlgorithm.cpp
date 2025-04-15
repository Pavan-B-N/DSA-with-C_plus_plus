
// https://leetcode.com/problems/majority-element/
/*
 Majority Element
 Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm
       int freq=0, ans=0;
       for(int ele:nums){
        if(freq==0){
            ans=ele;
        }

        if(ans==ele){
            freq++;
        }else{
            freq--;
        }
       }
       return ans;
            
    }
};