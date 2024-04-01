#include <iostream>
using namespace std;

// Recursive function to find GCD (HCF)
int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

// Recursive function to find LCM
int lcm_recursive(int a, int b) {
    return (a * b) / gcd_recursive(a, b);
}

// Function to find GCD (HCF) using iteration
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find LCM using iteration
int lcm_iterative(int a, int b) {
    return (a * b) / gcd_iterative(a, b);
}

int main() {
    int num1 = 12, num2 = 15;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm_recursive(num1, num2) << endl;
    cout << "HCF of " << num1 << " and " << num2 << " is: " << gcd_recursive(num1, num2) << endl;
    return 0;
}