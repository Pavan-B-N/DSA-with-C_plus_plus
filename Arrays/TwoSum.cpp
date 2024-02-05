//given an array of integers , return indices of the two numbers such that they add up to a specific target
//time complexity=o(n)
/*
int arr[]={2,6,1,6,4,7,5,9};
int target=9;

output = [0,5] i.e 2,7
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// using start and end pointer
//Time complexity = o(nlogn)
vector<int> twoSum(int arr[],int n,int target){
    sort(arr,arr+n);

    int start=0;
    int end=n-1;
    while(start<end){
        int sum=arr[start]+arr[end];
        if(sum==target){
            cout<<"Found "<<start<<" "<<end<<endl;
            return {start,end};
        }
        else if(sum>target){
            end--;
        }else{
            start++;
        }
    }
    return {-1,-1};
}

int main(){
    int arr[]={2,6,1,6,4,7,5,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=7;

    vector<int> res=twoSum(arr,n,target);
    for(int e:res){
        cout<<e<<" ";
    }
    return 0;
}