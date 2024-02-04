#include <iostream>
using namespace std;

void printArr(int arr[],int n);
void swap(int arr[],int i,int j);

int main(){
    int arr[]={10,5,2,3,7};
    
    int n=sizeof(arr)/sizeof(arr[0]);
    //bubble sort swap smallest first
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]>arr[j]){
    //             //swap
    //             swap(arr,i,j);
    //         }
    //     }
    // }
    
    //bubble sort swap highest first
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[i+1]){
                //swap
                swap(arr,i,j);
            }
        }
    }
    //print the array
    cout<<"Sorted Array is : ";
    printArr(arr,n);

    return 0;
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}