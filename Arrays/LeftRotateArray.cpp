#include <iostream>
using namespace std;

void rotate(int arr[],int n,int r);
void printArr(int arr[],int n);

int main(){
    int arr[]={2,4,6,8,10};
    rotate(arr,5,20);
    printArr(arr,5);
    return 0;
}
//left rotate
void rotate(int arr[],int n,int r){
    int temp[r];
    // store rotate elements in temporary array
    for(int i=0;i<r;i++){
        temp[i]=arr[i];
    }
    //swift the elements
    for(int i=0;i<n-r;i++){
        arr[i]=arr[i+r];
    }

    // push rotated elements
    for(int i=0;i<r;i++){
        arr[i+r+1]=temp[i];
    }
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}