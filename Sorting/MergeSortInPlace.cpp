#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> res(high-low+1);
    int i=low;// left subarray
    int j=mid+1; // right subarray
    int k=0;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            res[k]=arr[i++];
        }else{
            res[k]=arr[j++];
        }
        k++;
    }
    while(i<=mid){
        res[k++]=arr[i++];
    }
    while(j<=high){
        res[k++]=arr[j++];
    }

    // Copy elements back to the original array
    for (k = 0; k < res.size(); ++k) {
        arr[low + k] = res[k];
    }

}
void mergeSort(vector<int> &arr,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
void mergeSort(vector<int> &arr){
    mergeSort(arr,0,arr.size());
}
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

   mergeSort(arr);

    // Print the sorted array
    for (int elem : arr) {
        cout << elem << " ";
    }

    return 0;
}