// find all duplicate elements in an array and returns a new array 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

// Time complexity is o(nlogn)
// Space complexity is o(n)
vector<int> allDuplicates(int arr[],int n){
    sort(arr,arr+n);
    vector<int> res;
    for(int i=0;i<n-1;i++){
        bool isDuplicate=false;
        while(arr[i]==arr[i+1]){
            isDuplicate=true;
            i++;
        }
        if(isDuplicate){
            res.push_back(arr[i-1]);
        }
    }
    return res;
}

// Time complexity is o(n)
// Space complexity is o(n)
vector<int> duplicates(int arr[],int n){
    set<int> s;
    vector<int> res;
    for(int i=0;i<n;i++){
        int isExists=s.find(arr[i])!=s.end();
        if(isExists){
            res.push_back(arr[i]);
        }else{
            s.insert(arr[i]);
        }
    }
    return res;
}

// Time complexity is o(n)
// Space complexity is o(n)
vector<int> duplicatesUsingHashMap(int arr[],int n){
    map<int,int> hashMap;
    vector<int> duplicates;
    for(int i=0;i<n;i++){
        // If the element is already in the hash map, increment its frequency
        if (hashMap.find(arr[i]) != hashMap.end()) {
            hashMap[arr[i]]++;
        } else {
            // Otherwise, add the element to the hash map with frequency 1
            hashMap[arr[i]] = 1;
        }
    }
    for (auto& pair : hashMap) {
        if (pair.second > 1) {
            // Add the element to the duplicates vector
            duplicates.push_back(pair.first);
        }
    }
    return duplicates;
}
int main(){
    int arr[]={1,2,3,4,2,4,5,4,4,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    // vector<int> res=duplicates(arr,n);
    // vector<int> res=allDuplicates(arr,n);
    vector<int> res=duplicatesUsingHashMap(arr,n);
    for(int ele:res){
        cout<<ele<<" ";
    }
    return 0;
}