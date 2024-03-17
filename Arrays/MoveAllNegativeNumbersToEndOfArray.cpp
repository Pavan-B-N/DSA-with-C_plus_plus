/*
Given an unsorted array arr[] of size n having both negative and positive integers.
The task is place all negative element at the end of array without changing the order of positive element and negative element.

arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output :
1  3  2  11  6  -1  -7  -5

*/

#include <iostream>
#include <vector>
using namespace std;
// o(logn) - order is not maintained
void moveNegativeToEnd(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (arr[start] < 0)
        {
            swap(arr[start], arr[end]);
            end--;
        }
        start++;
    }
}
// time=o(n) and space=o(n) - order is maintained
void moveNegativeToEnd2(vector<int> &arr){
    int n = arr.size();
    vector<int> temp;// store negative elements

    int k=0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            temp.push_back(arr[i]);
            continue;
        }
        arr[k++]=arr[i];
    }
    
    for(auto &ele:temp){
        arr[k++]=ele;
    }
}
int main()
{
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    //moveNegativeToEnd(arr);
    moveNegativeToEnd2(arr);
    for (auto &ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}
