#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums,int target,int start,int end){
    if(start>end){
        return -1;
    }
    int mid=start+(end-start)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]>target){
        return binarySearch(nums,target,start,mid-1);
    }else{
        return binarySearch(nums,target,mid+1,end);
    }
}

int main(){
    vector<int> nums={ 1, 5, 8, 9, 10 };
    int target=8;
    int res=binarySearch(nums,target,0,nums.size());
    cout<<res;
    return 0;
}