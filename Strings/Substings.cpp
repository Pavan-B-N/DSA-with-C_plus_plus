#include <iostream>
#include <vector>
using namespace std;
// A substring is a contiguous sequence of characters within a string
void substrings(string str) {
    int n = str.length();

    for (int i = 0; i < n; i++) {
        for (int j = i ; j < n; j++) {
            cout << str.substr(i, (j - i)+1) << " ";
        }
    }
}

int main(){
    string str="abc";
    substrings(str);
}