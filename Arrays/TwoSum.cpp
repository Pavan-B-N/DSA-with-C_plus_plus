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
#include <set>
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

//HashSet -o(1)
//Time complexity = o(n)
vector<int> twoSumUsingSet(int arr[],int n,int target){
    set<int> s;
    for(int i=0;i<n;i++){
        int diff=target-arr[i];
        if(s.find(diff)!=s.end()){
            return {arr[i],diff};
        }
        s.insert(arr[i]);
    }
    return {-1,-1};
}
int main(){
    int arr[]={2,6,1,6,4,7,5,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=7;

    vector<int> res;
    // res=twoSum(arr,n,target);
    // res=twoSumUsingSet(arr,n,target);
    for(int e:res){
        cout<<e<<" ";
    }
    return 0;
}