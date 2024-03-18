/*
Given an array and an integer K, find the maximum for each and every contiguous subarray of size K.

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
    Maximum of 1, 2, 3 is 3
    Maximum of 2, 3, 1 is 3
    Maximum of 3, 1, 4 is 4
    Maximum of 1, 4, 5 is 5
    Maximum of 4, 5, 2 is 5 
    Maximum of 5, 2, 3 is 5
    Maximum of 2, 3, 6 is 6
*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// o((n-k+1)*k) = o(n*k)
void printMax(vector<int> arr,int k){
    int n=arr.size();
    int maxNum;
    for(int i=0;i<=n-k;i++){
        maxNum=arr[i];
        for(int j=1;j<k;j++){
            if(arr[i+j]>maxNum){
                maxNum=arr[i+j];
            }
        }
        cout<<maxNum<<" ";
    }
}

// Time = o(nlogn)
// Space = (O(N))
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    vector<int> ans;
    priority_queue<pair<int, int>> heap;

    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });

    ans.push_back(heap.top().first);

    for (int i = k; i < arr.size(); i++) {
        heap.push({ arr[i], i });

        while (heap.top().second <= i - k)
            heap.pop();

        ans.push_back(heap.top().first);
    }

    return ans;
}

int main(){
    vector<int> arr={1, 2, 3, 1, 4, 5, 2, 3, 6};
    // printMax(arr,3);
    vector<int> res=maxSlidingWindow(arr,3);
    for(auto &ele:res){
        cout<<ele<<" ";
    }
    return 0;
}