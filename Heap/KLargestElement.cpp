/*
Given an array Arr of N positive integers and an integer K, find K largest elements from the array

Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.


// maxHeap = priority queue is implemented as max heap by default in C++
priority_queue<int> pq;
priority_queue<pair<int, int>> heap;

// minHeap
priority_queue <int, vector<int>, greater<int>> gq;
where 
‘int’ is the type of elements you want to store in the priority queue.
‘vector<int>’ is the type of internal container used to store these elements
‘greater<int>‘ is a custom comparison function

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printKLargestElements(vector<int> &arr,int k){
    priority_queue<int> heap;
    for(int i=0;i<arr.size();i++){
        heap.push(arr[i]);
    }
    while(k>0 && !heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
        k--;
    }
}

int main(){
    vector<int> arr={12, 5, 787, 1, 23};
    printKLargestElements(arr,2);
    return 0;
}