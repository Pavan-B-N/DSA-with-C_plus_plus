/*
Given an array of integers, the task is to segregate even and odd numbers in the array. All even numbers should appear before odd numbers in the modified array, and the order of even and odd numbers should be preserved.

Input: [12, 34, 45, 9, 8, 90, 3]
Output: [12, 34, 8, 90, 45, 9, 3]
Explanation: Even numbers (12, 34, 8, 90) are moved to the beginning, and odd numbers (45, 9, 3) are moved to the end while preserving their original order.

Time Complexity: O(n) 
Auxiliary Space: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
// order is not maintained
void segregateEvenOdd(int arr[], int n) {
    int left = 0;  // Pointer for even numbers
    int right = n - 1;  // Pointer for odd numbers

    while (left < right) {
        // Move left pointer to the right until an odd number is found
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }

        // Move right pointer to the left until an even number is found
        while (arr[right] % 2 == 1 && left < right) {
            right--;
        }

        // Swap the elements at left and right pointers
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

//Space complexity is o(1)
void arrayEvenAndOdd(vector<int>& arr) {
    int evenIndex = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            // Swap the current element with the first odd element (evenIndex)
            swap(arr[i], arr[evenIndex]);
            evenIndex++;
        }
    }
}

int main()
{
    vector<int> arr = {12, 34,  8,9, 90, 3};
    // vector<int> arr = {7, 2, 9, 4, 6, 1, 3, 8, 5};
    // Function Call
    arrayEvenAndOdd(arr);
    cout << "Updated Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}