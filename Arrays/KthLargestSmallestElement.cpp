/*
K’th Smallest/Largest Element in Unsorted Array

Given an array arr[] of size N and a number K, where K is smaller than the size of the array. Find the K’th smallest element in the given arra
Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
Output: 7

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// o(nlogn)
int kthSmallest(vector<int> arr,int k){
    int n=arr.size();
    if(k>=n){
        return -1;
    }
    sort(arr.begin(),arr.end());
    return arr[k-1];
}

//other approaches includes priority queue and counting sort

int main(){
    vector<int> arr={7,10,4,3,20,15};
    cout<<kthSmallest(arr,3);
    return 0;
}