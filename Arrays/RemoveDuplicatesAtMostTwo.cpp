/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

*/
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int j = 0; // pointer to add elements
    int i = 0; // pointer to iterate the array

    while (i < n)
    {
        int ele = nums[i++];
        nums[j++] = ele;
        int c = 1;
        while (i < n && ele == nums[i])
        {
            if (c < 2)
            {
                nums[j++] = nums[i];
            }
            c++;
            i++;
        }
    }

    return j;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2,2,2,2,2,2, 3,3,3,3,4};
    int k = removeDuplicates(nums);
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}