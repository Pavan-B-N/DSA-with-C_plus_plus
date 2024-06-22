#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void miniMaxSum(vector<int> arr) {
    // Ensure we use a larger type to avoid overflow
    long long totalSum = 0;
    
    // Compute the total sum
    for(int ele : arr) {
        totalSum += ele;
    }
    
    // Find the minimum and maximum element
    int minElement = *min_element(arr.begin(), arr.end());
    int maxElement = *max_element(arr.begin(), arr.end());
    
    // Calculate min sum (exclude max element) and max sum (exclude min element)
    long long minSum = totalSum - maxElement;
    long long maxSum = totalSum - minElement;
    
    // Output the result
    cout << minSum << " " << maxSum << endl;
}

int main() {
    vector<int> arr(5);
    // Read the input
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    // Call the miniMaxSum function
    miniMaxSum(arr);
    return 0;
}
