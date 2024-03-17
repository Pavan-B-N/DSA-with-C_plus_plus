/*
Given Array of size n and a number k, find all elements that appear more than n/k times

Input: arr[] = {3, 1, 2, 2, 1, 2, 3, 3}, k = 4
Output: {2, 3}
Explanation: Here n/k is 8/4 = 2, therefore 2 appears 3 times in the array that is greater than 2 and 3 appears 3 times in the array that is greater than 2
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


// o(nlogn) = using sorting
void findElements(int arr[], int n, int k) {
    sort(arr, arr + n);

    int threshold = n / k;

    int i=0;
    while(i<n){
        int count=1;
        while(arr[i]==arr[i+1]){
            i++;
            count++;
        }
        if(count>threshold){
            cout<<arr[i]<<" ";
        }
        i++;
    }
}
// o(n) = hashing
void findElements2(int arr[], int n, int k) {
    unordered_map<int, int> freq;

    int threshold = n / k;

    // Count frequencies of elements in the array
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Iterate through the map to find elements with frequency greater than threshold
    cout << "Elements appearing more than " << n / k << " times: ";
    for (auto &it : freq) {
        if (it.second > threshold)
            cout << it.first << " ";
    }
}
int main() {
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    
    cout << "Elements appearing more than " << n / k << " times: ";
    findElements(arr, n, k);

    return 0;
}
