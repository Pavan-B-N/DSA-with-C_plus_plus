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
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    int n = arr.size();

    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];

        // Merge intervals as long as they overlap
        while (i + 1 < n && arr[i + 1][0] <= end) {
            end = max(end, arr[i + 1][1]);
            i++;
        }

        res.push_back({start, end});
    }

    for (const auto& interval : res) {
        cout << interval[0] << ", " << interval[1] << endl;
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