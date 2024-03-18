#include <iostream>
#include <vector>
using namespace std;

// o(n)
int maxOfSubarray(vector<int> arr,int k){
    int n=arr.size();
    int i=0;//start
    int j=0;//end;
    //calculate window size sum
    int maxSum=0;
    while(j<k && j<n){
        maxSum+=arr[j];
        j++;
    }
    // for the rest of the array
    while(j<n){
        maxSum=max(maxSum,maxSum+arr[j]-arr[i]);
        i++;
        j++;
    }
    return maxSum;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,10,30,5,2,3};
    cout<<"Max Sum : "<<maxOfSubarray(arr,3)<<endl;
    return 0;
}