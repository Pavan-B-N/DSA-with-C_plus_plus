/*
subsets of s="abc"
subsets=[a,b,c,ab,ac,bc,abc,""]
*/
// https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
    
void printVec(vector<vector<int>> vec){
    for(auto &arr:vec){
        cout<<"[ ";
        for(auto &ele:arr){
            cout<<ele<<",";
        }
        cout<<" ]";
    }
}
void printArr(vector<int> &arr){
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

// processed and unprocessed string
void subsets(string p,string up){
    if(up==""){
        cout<<p<<" ";
        return;
    }
    //consider it
    char ch=up[0];
    subsets(p+ch,up.substr(1,up.size()));
    //ignore it
    subsets(p,up.substr(1,up.size()));
}

void subsetsIncludingAscii(string p,string up){
    if(up==""){
        cout<<p<<" ";
        return;
    }
    //pick
    char ch=up[0];
    subsetsIncludingAscii(p+ch,up.substr(1,up.size()));

    //not pick
    subsetsIncludingAscii(p,up.substr(1,up.size()));

    //pick ascii
    subsetsIncludingAscii(p+to_string((int)ch),up.substr(1,up.size()));
}

void printSubSequences(vector<int> &arr,int n,int index,vector<int> &subSequence){
    if(index==n){
        printArr(subSequence);
        return;
    }

    //pick
    subSequence.push_back(arr[index]);
    printSubSequences(arr,n,index+1,subSequence); 
    // not pick
    subSequence.pop_back();
    printSubSequences(arr,n,index+1,subSequence);
}

// number of possible subsets = 2^N
// T.C = 2^N
// S.C = stack (N) + res (2^N)
// Subsets (contiguos or Non-contiguos,order is not maintained) == SubSequences (contiguos or Non-contiguos,order is maintained)
void findSubsets(vector<int>& nums, vector<vector<int>>& res,vector<int>& subset, int index) {
    if (index == nums.size()) {
        res.push_back(subset);
        return;
    }

    // not pick
    findSubsets(nums, res, subset, index + 1);

    // pick
    subset.push_back(nums[index]);
    findSubsets(nums, res, subset, index + 1);
    // Backtrack to remove the current element and restore state
    subset.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;// subsets
    vector<int> subset;// or subsequence
    findSubsets(nums, res, subset, 0);
    return res;
}


int main(){
    string str="abc";
    // subsets("",str);
    // subsetsIncludingAscii("",str);

    vector<int> arr={1,2,3};
    vector<vector<int>> res=subsets(arr);
    printVec(res);
    return 0;
}