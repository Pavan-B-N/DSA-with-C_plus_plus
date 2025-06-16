//find position of an element  in a sorted array of infinite numbers i.e we should not use arr.length
// arr= {1,2,3,4,5,6,7,8 .......}
#include <iostream>
using namespace std;
int binarySearch(int arr[],int start,int end,int target){
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

int findPositionOfInfiniteArray(int arr[], int target){
    int start=0;
    int end=1;
    while(target>arr[end]){
        start=end;
        end=end*2;
    }
    return binarySearch(arr,start,end,target);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int target=8;
    int res=findPositionOfInfiniteArray(arr,target);
    cout<<"Position is "<<res<<endl;
    return 0;
}