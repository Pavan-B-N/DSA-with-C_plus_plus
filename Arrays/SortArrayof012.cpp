/*
Sort an array of 0s, 1s and 2s | Dutch National Flag problem
*/
#include <iostream>
using namespace std;
void sort_dutch_arr(int arr[],int n){
    int l=0;
    int m=0;
    int h=n-1;
    while(m<=h){
        if(arr[m]==0){
            swap(arr[m],arr[l]);
            l++;
            m++;
        }else if(arr[m]==1){
            m++;
        }else if(arr[m]==2){
            swap(arr[m],arr[h]);
            h--;
        }
    }
}

int main(){
    int arr[]={0,1,2,0,0,1,1,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort_dutch_arr(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}