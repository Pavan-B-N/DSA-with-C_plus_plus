/*
Find Common Elements Between Two Arrays
You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values:

answer1 : the number of indices i such that nums1[i] exists in nums2.
answer2 : the number of indices i such that nums2[i] exists in nums1.
Return [answer1,answer2].

 

Example 1:

Input: nums1 = [2,3,2], nums2 = [1,2]

Output: [2,1]

https://leetcode.com/problems/find-common-elements-between-two-arrays/description/
*/

#include <vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> set1(nums1.begin(), nums1.end());
            unordered_set<int> set2(nums2.begin(), nums2.end());
    
            int answer1 = getCommonElementsCount(nums1, set1, set2);
            int answer2 = getCommonElementsCount(nums2, set1, set2);
    
            return {answer1, answer2};
        }
    
        int getCommonElementsCount(vector<int>& arr, unordered_set<int>& set1, unordered_set<int>& set2) {
            int count = 0;
            for(auto ele : arr) {
                if(set1.count(ele) && set2.count(ele)) {
                    count++;
                }
            }
            return count;
        }
    };
    