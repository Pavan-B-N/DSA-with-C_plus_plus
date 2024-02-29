#include <iostream>
#include <climits>
using namespace std;
int threeLargest(int arr[],int n){
    int largest=INT_MIN;
    int slargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }else if(arr[i]>slargest && arr[i]<largest){
            slargest=arr[i];
        }
    }
    return slargest;
}
int main(){
    int arr[]={5,7,8,9,21,66,44,55,10,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<threeLargest(arr,n);
    return 0;   
}