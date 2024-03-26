#include <iostream>
#include <string>
using namespace std;

void possibleCombinations(string p, int target) {
    if (target == 0) {
        cout << p << " ";
        return;
    }
    // dice can have only 6 numbers
    for (int i = 1; i <= 6 && i <= target; i++) {
        possibleCombinations(p + to_string(i), target - i);
    }
}

int main() {
    possibleCombinations("", 4);
    // 1111 112 121 13 211 22 31 4 
    return 0;
}
