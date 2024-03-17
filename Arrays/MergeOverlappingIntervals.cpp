/*
nput: Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], [9,10].
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());

    vector<vector<int>> res;

    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!res.empty() && end<=res.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }else{
                break;
            }
        }
        res.push_back({start,end});
    }
    return res;
}

int main(){
    vector<vector<int>> arr={{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> res=mergeOverlappingIntervals(arr);
    for(auto &interval:res){
        cout<<"{ "<<interval[0]<<" , "<<interval[1]<<" }"<<" ,";
    }
    return 0;
}