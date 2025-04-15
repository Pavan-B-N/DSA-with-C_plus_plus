// https://leetcode.com/problems/majority-element/
#include <iostream>
#include <vector>
using namespace std;
#include <map>
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