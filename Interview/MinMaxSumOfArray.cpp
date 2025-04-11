#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void miniMaxSum(vector<int> &arr) {
    int min=*min_element(arr.begin(),arr.end());
    int max=*max_element(arr.begin(),arr.end());

    long long totalSum = 0;
  
    for(int ele : arr) {
        totalSum += ele;
    }

    long long minSum = totalSum - max;
    long long maxSum = totalSum - min;

    cout << minSum << " " << maxSum << endl;
}

int main() {
    vector<int> arr={5,9,2,9,29,52,5,5};

    miniMaxSum(arr);
    return 0;
}
