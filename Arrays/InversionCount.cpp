/*
Given an array arr[]. The task is to find the inversion count of arr[]. Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

*/

// o(n^2)
#include <iostream>
#include <vector>
using namespace std;

// o(n^2)
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
 
    return inv_count;
}

vector<int> merge(vector<int> arr1,vector<int> arr2,int &invc){
    int n1=arr1.size();
    int n2=arr2.size();
    vector<int> res(n1 + n2);
    int i=0;
    int j=0;
    int k=0;

    while(i<n1 && j<n2){
        //inversion count
        if(arr1[i]>arr2[j]){
            invc += (n1 - i); // counting inversions 
            res[k++]=arr2[j++];
        }else{
            res[k++]=arr1[i++];
        }
    }
    while(i<n1){
        res[k++]=arr1[i++];
    }
    while(j<n2){
        res[k++]=arr2[j++];
    }
    
    return res;
}

vector<int> merge_sort(vector<int> arr,int &invc){
    if(arr.size()==1){
        return arr;
    }
    int mid=arr.size()/2;
     // Split the vector into two halves
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
   
   // Recursively sort each half
    left = merge_sort(left,invc);
    right = merge_sort(right,invc);

    return merge(left,right,invc);
}

// o(nlogn)
int invCount(vector<int> arr){
    int invc=0;
    merge_sort(arr,invc);
    return invc;
}