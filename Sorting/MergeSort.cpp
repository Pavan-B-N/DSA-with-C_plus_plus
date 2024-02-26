#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> arr1,vector<int> arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    vector<int> res(n1 + n2);
    int i=0;
    int j=0;
    int k=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            res[k++]=arr1[i++];
        }else{
            res[k++]=arr2[j++];
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

vector<int> merge_sort(vector<int> arr){
    if(arr.size()==1){
        return arr;
    }
    int mid=arr.size()/2;
     // Split the vector into two halves
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
   
   // Recursively sort each half
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left,right);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    vector<int> sorted_arr = merge_sort(arr);

    // Print the sorted array
    for (int elem : sorted_arr) {
        cout << elem << " ";
    }

    return 0;
}