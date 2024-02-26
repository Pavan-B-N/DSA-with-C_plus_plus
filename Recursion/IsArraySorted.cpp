#include <iostream>
#include <vector>
using namespace std;
bool isArraySorted(vector<int> &nums,int i){
    if(i==nums.size()-1){
        return true;
    }
    if(nums[i]>nums[i+1]){
        return false;
    }
    return nums[i]<nums[i+1] && isArraySorted(nums,i+1);
}

bool isArraySorted(vector<int> &nums){
    return isArraySorted(nums,0);
}
int main(){
    vector<int> nums={1,2,3,4,5,6};
    cout<<isArraySorted(nums);
    return 0;
}