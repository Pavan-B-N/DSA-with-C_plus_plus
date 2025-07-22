#include <vector>
#include <iostream>
using namespace std;

void reverse(vector<int> &arr,int start,int end){
    if(start>=end){
        return;
    }
    swap(arr[start],arr[end]);
    reverse(arr,start+1,end-1);
}

int main(int argc, char const *argv[])
{
    vector<int> arr={1,2,3,4,5};
    int n=arr.size();
    reverse(arr,0,n-1);
    for(int num : arr){
        cout << num << " ";
    }
    return 0;
}
