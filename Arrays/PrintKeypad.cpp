/*
abc  def  ghi  
jkl  mno  pqr  
stu  vwx  yz  
*/
#include <iostream>

using namespace std;

void printKeypad() {
    // ASCII value for 'a' = 97
    for (int num = 0; num < 9; num++) {
        char c1 = 'a' + num * 3;
        char c2 = 'b' + num * 3;
        char c3 = 'c' + num * 3;
        cout << c1 << c2;
        // 'c' is skipped if it exceeds 'z'
        if (isalpha(c3)) {
            cout << c3;
        }
        cout << "  ";
        // newline after every 3 characters
        if ((num + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

int main() {
    printKeypad();
    return 0;
}
