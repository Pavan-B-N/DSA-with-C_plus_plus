/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.
*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool isValidSubstring(const string& s, int start, int end) {
    int balance = 0;
    for (int i = start; i <= end; ++i) {
        if (s[i] == '(')
            balance++;
        else if (s[i] == ')') {
            balance--;
            if (balance < 0)
                return false; // More close parentheses than open ones
        }
    }
    return balance == 0; // True if balanced parentheses
}
// Naive Approach:
int longestValidSubstringNaive(const string& s) {
    int n = s.length();
    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isValidSubstring(s, i, j)) {
                max_length = max(max_length, j - i + 1);
            }
        }
    }
    return max_length;
}

//stack approach
int longestValidSubstringStack(const string& s) {
    stack<int> st;
    st.push(-1); // To handle edge cases
    int max_length = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i); // Reset starting point
            } else {
                max_length = max(max_length, i - st.top());
            }
        }
    }
    return max_length;
}


int main() {
    string s = "((()()";
    cout << "Length of the longest valid substring: " << longestValidSubstringNaive(s) << endl;
    cout << "Length of the longest valid substring: " << longestValidSubstringStack(s) << endl;
    return 0;
}
