// Assign C cows to N stalls such that min distance between them is largest possible.
// return largest minimum distance
/*
n=5
c=3
arr=[1,2,8,4,9]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist) {
    int cows = 1, lastStallPos = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] - lastStallPos >= minAllowedDist) {
            cows++;
            lastStallPos = arr[i];
        }
    }

    if (cows == C) {
        return true;
    }

    return false;
}

int getDistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(), arr.end()); // N log N

    int st = 1, end = arr[N - 1] - arr[0], ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, N, C, mid)) { // right
            ans = mid;
            st = mid + 1;
        } else { // left
            end = mid - 1;
        }
    }

    return ans;
}
