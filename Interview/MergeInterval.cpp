// https://leetcode.com/problems/merge-intervals/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    vector<vector<int>> arr = {
        {1, 4}, {6, 8}, {9, 10}, {2, 5}, {7, 10}
    };

    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    int n = arr.size();
    int i = 0;

    while (i < n) {
        int start = arr[i][0];
        int end = arr[i][1];

        // Merge intervals as long as they overlap
        while (i + 1 < n && arr[i + 1][0] <= end) {
            end = max(end, arr[i + 1][1]);
            i++;
        }

        res.push_back({start, end});
        i++; // move to next non-overlapping interval
    }

    for (const auto& interval : res) {
        cout << interval[0] << ", " << interval[1] << endl;
    }

    return 0;
}
