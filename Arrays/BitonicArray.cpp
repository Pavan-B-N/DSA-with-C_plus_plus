// A bitonic sequence isa sequence of numbers that is first strictly increasing then after a point deceasig
/*
Bitonic array is also known as mountain array
arr={1,3,5,7,5,3,1}

find the peak index of bitonic or mountain array

*/
#include <iostream>
using namespace std;

// logn time complexity
// also known as pivot element
int peak(int arr[],int len){
    //use binary search instead of linear search
    int start=0;
    int end=len-1;
    int mid=0;
    while(start<end){
        mid=start+(end-start)/2; // efficient
        // mid=(start+end)/2;
        if(arr[mid]>arr[mid+1]){
            end=mid;
        }else{
            start=mid+1;
        }
    }
     // return start or end because both points to the same element
    return arr[end];
}
int main(){
    int arr[]={1,3,5,7,5,3,1};
    int len=sizeof(arr)/sizeof(arr[0]);

    int res=peak(arr,len);
    cout<<"Peak of Bitonic array is "<<res<<endl;
    return 0;
}