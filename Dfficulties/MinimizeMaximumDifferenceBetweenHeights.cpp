/*
Minimize the maximum difference between the heights

Given the heights of N towers and a value of K, Either increase or decrease the height of every tower by K
After modifications, the task is to minimize the difference between the heights of the longest and the shortest tower and output its difference.

Input: arr[] = {1, 15, 10}, k = 6
Output:  Maximum difference is 5.


Explanation: 
tall=15
short=1
difference between tall-short = 14, so we need to minimize the difference between heights

The idea is to increase the first i towers by k and decrease the rest tower by k after sorting the heights, then calculate the maximum height difference.

Array after sorting => arr[] = {1, 10, 15}

initially maxHeight = arr[n – 1] = 15
            minHeight = arr[0] = 1
            ans = maxHeight – minHeight = 15 – 1 = 14



Change 1 to 7, 15 to 9 and 10 to 4. 
{7,9,4}

Maximum difference is 5 (between 4 and 9). We can’t get a lower difference.


*/
#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n); // Sort the array of heights

    // Initialize the maximum possible height difference
    int ans = arr[n - 1] - arr[0];
    
    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    // Iterate through the array to find the minimum maximum difference
    for (int i = 1; i < n; i++) {
        if (arr[i] - k < 0)
            continue;
        
        // Calculate the minimum element when adding k to the whole array
        tempmin = min(arr[0] + k, arr[i] - k);

        // Calculate the maximum element when subtracting k from the whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k);

        // Update ans with the minimum difference
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

int main() {
    const int k = 6, n = 6;
    int arr[n] = { 7, 4, 8, 8, 8, 9 };
    int ans = getMinDiff(arr, n, k);
    cout << ans; // Output the minimum maximum difference
    return 0;
}
