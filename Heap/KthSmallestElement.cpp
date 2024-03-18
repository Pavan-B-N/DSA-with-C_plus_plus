#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int N, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        minHeap.push(arr[i]);
    }

    for (int i = 0; i < K - 1; i++) {
        minHeap.pop();
    }

    return minHeap.top();
}

int main() {
    const int N = 10;
    int arr[N] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int K = 4;

    cout << "Kth Smallest Element is: " << kthSmallest(arr, N, K) << endl;

    return 0;
}
