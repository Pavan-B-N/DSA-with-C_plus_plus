/*
Google question
given a string containing digits from 2-9 inclusive , return all possible letter combination that the number could represent
digit = "23"
2="abc"
3="def"
4="ghi"
so each number has 3 letter 
so 3*9 = 27 -1 = 26
hence 9 has only two letters
according to key 2=abc 3=def 
output = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to print all possible letter combinations
void printLetterCombinations(string p, string up) {
    // If there are no more digits left to process, print the current combination and return
    if (up.empty()) {
        cout << p << " ";
        return;
    }

    int num = up[0] - '0';

    // Calculate the characters corresponding to the digit
    char c1 = 'a' + (num - 1) * 3;
    char c2 = 'b' + (num - 1) * 3;
    char c3 = 'c' + (num - 1) * 3;
    
    printLetterCombinations(p + c1, up.substr(1));
    printLetterCombinations(p + c2, up.substr(1));

    if (isalpha(c3)) {
        printLetterCombinations(p + c3, up.substr(1));
    }
}

int main() {
    printLetterCombinations("", "12");
    cout << endl;

    return 0;
}
