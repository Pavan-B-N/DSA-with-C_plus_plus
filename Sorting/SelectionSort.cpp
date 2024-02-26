#include <iostream>
#include <algorithm>
using namespace std;
// time complexity is o(n^2)
void sort_array(int arr[],int n){
    for(int i=0;i<(n-1);i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={7,4,10,8,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort_array(arr,n);
    printArray(arr,n);
    return 0;
}