/*
search in rotated sorted array
Note : array doesn't contains duplicates
int arr[] = { 15, 18, 2, 3, 6, 12 };
*/
#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int start,int end,int target){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]>target){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}
int findPivot(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid]<arr[mid-1]){
            return mid-1;
        }else if(arr[start]>=arr[mid]){
            end=mid-1;
        }else{
            start=mid;
        }
    }
    return -1;
}
int search(int arr[],int n,int target){
    int pivot=findPivot(arr,n);
    int index=binarySearch(arr,n,0,pivot,target);
    if(index==-1){
        index=binarySearch(arr,n,pivot+1,n-1,target);
    }
    return index;
}

int main(){
    int arr[] = { 15, 18, 2, 3, 6, 12 };
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=6;
    int i=search(arr,n,target);
    cout<<i<<endl;
}