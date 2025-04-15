

// https://leetcode.com/problems/two-sum/submissions/1603917016/
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;



// o(n) = space , time 
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (map.find(diff) != map.end()) {
            return {map[diff], i};  // diff found earlier, return indices
        }
        map[nums[i]] = i;  // store current element after checking
    }
    return {-1, -1};
}


// using two pointer method
//Time complexity = o(nlogn)
// if array is sorted then o(n)
vector<int> twoSum(int arr[],int n,int target){
    sort(arr,arr+n);

    int start=0;
    int end=n-1;
    while(start<end){
        int sum=arr[start]+arr[end];
        if(sum==target){
            cout<<"Found "<<start<<" "<<end<<endl;
            return {arr[start],arr[end]};
        }
        else if(sum>target){
            end--;
        }else{
            start++;
        }
    }
    return {-1,-1};
}