#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target);

int main(){
    // array must be sorted for binary search
    /////////  0 1 2 3 4  
    int arr[]={2,4,6,8,10};
    int target=8;

    int start=0;
    int end=6;
    
    int res=binarySearch(arr,start,end,target);
    cout<<"Target "<<target<<" Found at Index "<<res;

    return 0;
}

// time complexity is logn
int binarySearch(int arr[], int start, int end, int target){
    while(start<=end){
        int mid=(start+end)/2;
        if(target==arr[mid]){
            return mid;
        }else if(target>arr[mid]){
            start=mid+1;
        }else{
            // target<arr[mid]
            end=mid-1;
        }
    }
    return -1;
}