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

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    map<int,int> m;
    //count
    for(auto &num:nums){
        m[num]++;
    }
    //print map
    for(auto &pair:m){
        cout<<pair.first<<":"<<pair.second<<endl;
    }
    n = n/2;
    for(auto x: m){
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