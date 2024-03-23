#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void eratosthenes(int n) {
    vector<int> arr(n); // Initialize an array of size n

    // Initialize the array with numbers from 0 to n-1
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Iterate through numbers from 2 to sqrt(n)
    for (int i = 2; i * i < n; i++) {
        if (arr[i] != 0) { // If i is prime
            // Mark multiples of i as non-prime
            for (int j = i * 2; j < n; j += i) {
                arr[j] = 0;
            }
        }
    }

    // Print prime numbers
    for (int i = 2; i < n; i++) {
        if (arr[i] != 0) {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    int n = 100;
    eratosthenes(n);
    return 0;
}
