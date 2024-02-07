#include <iostream>

int setKthBit(int n, int k) {
    int mask = 1 << (k - 1);
    return n | mask;
}

int main() {
    int n = 4; // 100
    int k = 1;
    // 101 = 5
    int ans = setKthBit(n, k);
    std::cout << ans << std::endl;

    return 0;
}