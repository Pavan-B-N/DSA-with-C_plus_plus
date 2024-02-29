/*
segregate positive and negative numbers in an array
nums = [3,1,-2,-5,2,-4]
output=[-2,-5,-4,3,1,2]

//order must be maintained and time complexity must be o(n)
*/
#include <iostream>
#include <vector>
using namespace std;
void segregate(vector<int> &nums){
    int n=nums.size();
    int negativeIndex=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            swap(nums[i],nums[negativeIndex]);
            negativeIndex++;
        }
    }
}


int main(){
    vector<int> nums={3,1,-2,-5,2,-4};
    segregate(nums);

    for(auto &ele:nums){
        cout<<ele<<" ";
    }
    return 0;
}