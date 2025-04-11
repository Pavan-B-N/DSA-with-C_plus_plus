/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

https://leetcode.com/problems/find-smallest-letter-greater-than-target/
*/

#include <vector>
using namespace std;
class Solution
{
public:
    // always logn
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=binarySearch(nums,target);
         int last=binarySearch(nums,target,false);
         return {first,last};
     }
 
     int binarySearch(vector<int>& nums, int target,bool firstIndex=true){
         int start=0;
         int end=nums.size()-1;
         int foundIndex=-1;
         while(start<=end){
             int mid=start+(end-start)/2;
             if(nums[mid]==target){
                 foundIndex=mid;
                 if(firstIndex){
                     end=mid-1;
                 }else{
                     start=mid+1;
                 }
             }
             else if(nums[mid]>target){
                 end=mid-1;
             }else{
                 start=mid+1;
             }
         }
         return foundIndex;
     }
    // O(log n) + O(n) in worst case
    // [2, 2, 2, 2, 2, 2, 2, 2, 2, 2]  // many repeated elements
    vector<int> searchRange1(vector<int> &nums, int target)
    {
        //  vector<int> res;
        int firstTarget = -1;
        int secondTarget = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                // res.push_back(mid);
                firstTarget = mid;
                secondTarget = mid;
                break;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        if (firstTarget == -1)
        {
            return {-1, -1};
        }

        while (firstTarget >= 0 && nums[firstTarget] == target)
        {
            firstTarget--;
        }
        firstTarget++;

        while (secondTarget < nums.size() && nums[secondTarget] == target)
        {
            secondTarget++;
        }
        secondTarget--;

        return {firstTarget, secondTarget};
    }
};