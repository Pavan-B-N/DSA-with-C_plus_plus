// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <vector>
using namespace std;
// tag: [favorite]

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minIndex=findPivot(nums)+1;
        return nums[minIndex];
    }
    int findPivot(vector<int>& nums){
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(mid+1 < nums.size() && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[start] > nums[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }
};