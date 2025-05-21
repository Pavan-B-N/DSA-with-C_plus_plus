/*
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;
// use moore's algorithms for this

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    map<int,int> freq;
    //count
    for(auto &num:nums){
        freq[num]++;
    }
    //print map
    for(auto &pair:freq){
        cout<<pair.first<<":"<<pair.second<<endl;
    }
    n = n/2;
    for(auto x: freq){
        if(x.second > n){
            return x.first;
        }
    }
    return 0;
}

int main(){
    vector<int> nums={2,2,1,1,1,2,2};
    int res=majorityElement(nums);
    cout<<"majority element is "<<res;
    return 0;
}