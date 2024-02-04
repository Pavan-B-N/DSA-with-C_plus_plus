// find all duplicate elements in an array and returns a new array 
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Time complexity is o(nlogn)
vector<int> duplicates(int arr[],int n){
    set<int> s;
    vector<int> res;
    for(int i=0;i<n;i++){
        //s.count(ele)>0
        int isExists=s.find(arr[i])!=s.end();
        // int isExists=s.count(arr[i])>0;
        if(isExists){
            res.push_back(arr[i]);
        }else{
            s.insert(arr[i]);
        }
    }
    return res;
}
int main(){
    int arr[]={1,2,3,4,2,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> res=duplicates(arr,n);
    for(int ele:res){
        cout<<ele<<" ";
    }
    return 0;
}