//  1010 = 2
//  100 = 1
#include <iostream>
using namespace std;

int countSetBits(int n) {
    int setBits = 0;
    while (n > 0) {
        int lsb = n & 1;
        if (lsb == 1) {
            setBits++;
        }
        n >>= 1;
    }
    return setBits;
}

int main() {
    int n = 11; // 3
    int ans = countSetBits(n);
    cout << ans << endl;
    return 0;
}
