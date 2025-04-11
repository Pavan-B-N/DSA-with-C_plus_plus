/*
Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?

https://leetcode.com/problems/majority-element-ii/description/
*/

#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n=nums.size();
            int threshold=n/3;
            unordered_map<int,int> freq;
    
            for(auto &ele:nums){
                freq[ele]++;
            }
    
            vector<int> res;
            for(auto &pair:freq){
                int ele=pair.first;
                int freq=pair.second;
                if(freq>threshold){
                    res.push_back(ele);
                }
            }
            return res;
    
        }
    };