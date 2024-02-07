//1010
//n=10 k=3 o=1110=14
//n=10 k=1 o=1011=11
#include <iostream>
using namespace std;

int resetBit(int n, int k) {
    int mask = 1 << (k - 1);
    return n ^ mask;
}

int main() {
    int n = 10;
    int k = 1;
    cout << resetBit(n, k) << endl;

    return 0;
}
