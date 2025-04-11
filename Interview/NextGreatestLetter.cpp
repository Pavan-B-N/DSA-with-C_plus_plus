#include <iostream>
#include <vector>

using namespace std;

// Function to find the smallest letter greater than the target (ceil)
// Binary Search is used
// If no element is found greater than the target, return the first letter from the array
// The letters are considered to be wrapped around, so if the target is 'z', the result will be the first letter of the array
char nextLetter(vector<char>& letters, char target) {
    int start = 0;
    int end = letters.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        // If target is found at mid, increment start to find the next letter greater than target
        if (target == letters[mid]) {
            start = mid + 1;
            break;
        }
        // If target is less than the element at mid, search in the left half
        if (target < letters[mid]) {
            end = mid - 1;
        } else {
            // If target is greater than the element at mid, search in the right half
            // Update start because even when both elements are equal, we need to find the next letter
            start = mid + 1;
        }
    }
    // Return the smallest element greater than the target (ceil)
    return letters[start % letters.size()];
}

int main() {
    // Example usage
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'j'; // c
    cout << nextLetter(letters, target) << endl;
    return 0;
}
