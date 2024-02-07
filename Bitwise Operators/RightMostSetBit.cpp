//find the position of the right most set bit
//11110000 = 5
//10100 = 3
//1010 = 2
//01 = 1 , so k=5

#include <iostream>

int rightMostSetBit(int n) {
    int k = 1;
    while (n > 0) {
        if (n & 1) {
            return k;
        }
        n = n >> 1;
        k++;
    }
    return -1;
}

int main() {
    int n = 4; // 100, k = 3
    int ans = rightMostSetBit(n);
    std::cout << ans << std::endl;

    return 0;
}
