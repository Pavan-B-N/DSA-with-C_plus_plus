//find first and last position of an element in the sorted array
//nums=[5,7,7,8,8,10] target=8
//output =[3,4]
#include <iostream>
#include <vector>
using namespace std;

int binarysearch(int arr[],int n,int target,int findFirstIndex){
    int start=0;
    int end=n-1;
    int index=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            index=mid;
            //find first and last position
            if(findFirstIndex){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else if(arr[mid]>target){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return index;
}

vector<int> matchRange(int arr[],int n,int target){
    vector<int> res;
    int startPosition=binarysearch(arr,n,target,1);
    int endPosition=binarysearch(arr,n,target,0);

    res.push_back(startPosition);
    res.push_back(endPosition);

    return res;
}

int main(){
    int arr[]={5,7,7,8,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=8;

    vector<int> res=matchRange(arr,n,target);

    for(int ele:res){
        cout<<ele<<" ";
    }
    return 0;
}