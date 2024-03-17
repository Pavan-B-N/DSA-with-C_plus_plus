#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// O(n1 + n2 + n3) = unordered_map
// O((n1 + n2 + n3) * log n1) = map
void findCommon(const vector<int>& arr1, const vector<int>& arr2, const vector<int>& arr3) {
    unordered_map<int, int> freq;

    // Count frequency of elements in the first array
    for (int num : arr1)
        freq[num] = 1;

    // Iterate through the second array and update frequency map
    for (int num : arr2) {
        if (freq[num] == 1)
            freq[num]++;
    }

    // Iterate through the third array and find common elements
    for (int num : arr3) {
        if (freq[num] == 2) {
            cout << num << " ";
        }
    }
}

// O(n1 + n2 + n3)
void findCommon2(const vector<int>& ar1, const vector<int>& ar2, const vector<int>& ar3) {
    // Initialize starting indexes for ar1[], ar2[] and ar3[]
    int i = 0, j = 0, k = 0;

    // Iterate through three arrays while all arrays have elements
    while (i < ar1.size() && j < ar2.size() && k < ar3.size()) {

        // If x = y and y = z, print any of them and move ahead in all arrays
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
            cout << ar1[i] << " ";
            i++;
            j++;
            k++;
        }

        // x < y
        else if (ar1[i] < ar2[j])
            i++;

        // y < z
        else if (ar2[j] < ar3[k])
            j++;

        // We reach here when x > y and z < y, i.e., z is smallest
        else
            k++;
    }
}

int main() {
    vector<int> arr1 = {1, 5, 10, 20, 40, 80, 80}; // Duplicate 80
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};

    cout << "Common elements are: ";
    findCommon(arr1, arr2, arr3);
    cout << endl;

    return 0;
}
