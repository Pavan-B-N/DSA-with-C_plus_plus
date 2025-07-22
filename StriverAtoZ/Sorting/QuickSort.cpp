#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr,int low,int high){
    //pivot can be any random element in the array between the range l,h
    int pivot=arr[low];

    int i=low;
    int j=high;

    while(i<j){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return j;
}
void quickSort(vector<int> &arr,int low,int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot);
        quickSort(arr,pivot+1,high);
    }
}
void quickSort(vector<int> &arr){
    quickSort(arr,0,arr.size());
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

   quickSort(arr);

    // Print the sorted array
    for (int elem : arr) {
        cout << elem << " ";
    }

    return 0;
}