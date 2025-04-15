/*
Permutations of a given string

Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. 

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
// n! is the number of possible permuations
// processed and unprocessed string
void printPermutations(string p, string up) {
    if (up.empty()) {
        cout << p << " ";
        return;
    }
    char ch = up[0];
    for (int i = 0; i <= p.length(); i++) {
        string f = p.substr(0, i);
        string s = p.substr(i, p.length());
        printPermutations(f + ch + s, up.substr(1));
    }
}

int main() {
    printPermutations("", "abc");
    return 0;
}

