/*
Given an unsorted array of positive integers, find the number of triangles that can be formed with three different array elements as three sides of triangles.

For a triangle to be possible from 3 values, the sum of any of the two values (or sides) must be greater than the third value

input: arr= {4, 6, 3, 7}
Output: 3
Explanation: There are three triangles
possible {3, 4, 6}, {4, 6, 7} and {3, 6, 7}.

https://leetcode.com/problems/valid-triangle-number/editorial/

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// brute force
// Time complexity :O(n^3)
int triangleNumber(int nums[],int n)
{
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] > nums[k] &&
                    nums[i] + nums[k] > nums[j] &&
                    nums[j] + nums[k] > nums[i])
                {
                    count++;
                }
            }
        }
    }
    return count;
}

// Time complexity: O(N2).
// o(nlogn+o^2) = o(n^2)
int triangleNumber(vector<int>& nums) {
    int n=nums.size();
    int count=0;
    sort(nums.begin(),nums.end());
    for(int i=n-1;i>1;i--){
        int l=0;
        int r=i-1;
        while(l<r){
            if(nums[l]+nums[r]>nums[i]){
                count+=r-l;
                r--;
            }else{
                l++;
            }
        }
    }
    return count;
}