// https://leetcode.com/problems/valid-parentheses/submissions/1604903174/
#include <stack>
#include <string>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char> charStack;
            for (int i = 0; i < s.length(); i++) {
                char ch = s.at(i);
                if (ch == '(' || ch == '{' || ch == '[') {
                    charStack.push(ch);
                } 
                else if (charStack.empty()) {
                    return false;
                } 
                else if (((ch == ')' && charStack.top() == '(') || 
                                                (ch == '}' && charStack.top() == '{') || 
                                                (ch == ']' && charStack.top() == '['))) {
                    charStack.pop();
                } 
                else {
                    return false;
                }
            }
            return charStack.empty();
        }
    };
    