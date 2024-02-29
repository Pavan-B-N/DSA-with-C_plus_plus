#include <iostream>
#include <climits>
using namespace std;
// another way is to sort the array in descending order
void threeLargest(int arr[],int n){
    int first,second,third;
    first=second=third=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>first){
            third=second;
            second=first;
            first=arr[i];
        }else if(arr[i]>second && arr[i]<first){
            third=second;
            second=arr[i];
        }else if(arr[i]>third && arr[i]<second){
            third=arr[i];
        }
    }
    cout<<"first: "<<first<<endl;
    cout<<"second: "<<second<<endl;
    cout<<"third: "<<third<<endl;
}
int main(){
    int arr[]={5,7,8,9,21,66,44,55,10,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    threeLargest(arr,n);
    return 0;   
}