
// given an array of range 1-n , find the missing numbers in the array
// google question
/*
  int[] arr = { 4, 3, 2, 7, 8, 2, 3, 1 };// 8
// output - [5,6]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void cyclicSort(int arr[],int n){
    for(int i=0;i<n;i++){
        while(i!=arr[i]-1){
            //skip duplicates
            if(arr[i]==arr[arr[i]-1]){
                break;
            }
            swap(arr[i],arr[arr[i]-1]);
        }
    }
}

vector<int> missingNumbers(int arr[],int n){
    cyclicSort(arr,n);
    vector<int> res;
    for(int i=0;i<n;i++){
        if(i!=arr[i]-1){
            res.push_back(i+1);
        }
    }
    return res;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = { 4, 3, 2, 7, 8, 2, 3, 1 };
    int n=sizeof(arr)/sizeof(arr[0]);

    vector<int> res=missingNumbers(arr,n);
    for(int ele:res){
        cout<<ele<<" ";
    }
    return 0;
}
