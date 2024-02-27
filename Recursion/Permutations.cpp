#include <iostream>
#include <string>
using namespace std;
void permutations(string p, string up) {
    if (up.empty()) {
        cout << p << std::endl;
        return;
    }

    char ch = up[0];

    for (int i = 0; i <= p.length(); i++) {
        string f = p.substr(0, i);
        string s = p.substr(i);
        permutations(f + ch + s, up.substr(1));
    }
}

int permutationsCount(string p, string up) {
    if (up.empty()) {
        cout << p << std::endl;
        return 1;
    }

    char ch = up[0];

    int count=0;
    for (int i = 0; i <= p.length(); i++) {
        string f = p.substr(0, i);
        string s = p.substr(i);
        count+=permutationsCount(f + ch + s, up.substr(1));
    }
    return count;
}

// Example usage:
int main() {
    permutations("","abc");
    // cout<<permutationsCount("","abc");
    return 0;
}
