/*
A subarray is a contiguous part of the array
*/
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> subArrays(vector<int> &arr){
    vector<vector<int>> res;
    int n=arr.size();
    for(int i=0;i<n;i++){
        vector<int> inner;
        for(int j=i;j<n;j++){
            inner.push_back(arr[j]);
            res.push_back(inner);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> arr={1,2,3,4};
    vector<vector<int>> subarr=subArrays(arr);
    for(auto arr:subarr){
        cout<<"[ ";
        for(auto ele:arr){
            cout<<ele<<" ";
        }
        cout<<" ] "<<endl;
    }

    return 0;
}

