// https://leetcode.com/problems/remove-k-digits/

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

// O(N+K)
class Solution {
public:
    string removeKdigits(string num, int k) {
        // we end up removing everything
        if (k >= num.length()) {
            return "0";
        }
        stack<char> s;
        for (char ch : num) {
            // lexicographical comparision
            // smaller elements
            while (!s.empty() && s.top() > ch && k > 0) {
                s.pop();
                k--;
            }
            s.push(ch);
        }
        // if k is not zero, remove k elements from stack which are largest and arranged in decreasing like of order
        while (k > 0) {
            s.pop();
            k--;
        }

        // optional as removeLeadingZeros handles this
        if(s.empty()){
            return "0";
        }
        // building ans
        // this also handle if s.empty() return "0"
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        return removeLeadingZeros(ans);
    }

    string removeLeadingZeros(string str) {
        int i = 0;
        while (i < str.length() && str[i] == '0') {
            i++;
        }

        return i < str.length() ? str.substr(i) : "0";
    }
};


// exponential, TLE
class Solution {
public:
    string removeKdigits(string num, int k) {
        // Base case: if k == 0, return the number
        if (k == 0) return removeLeadingZeros(num);
        
        // If length is less than or equal to k, return "0"
        if (num.length() <= k) return "0";
        
        string minNum = "";
        for (int i = 0; i < num.length(); i++) {
            string newNum = num.substr(0, i) + num.substr(i + 1);  // remove one digit
            string candidate = removeKdigits(newNum, k - 1);       // recursive call
            if (minNum == "" || isSmaller(candidate, minNum)) {
                minNum = candidate;
            }
        }

        return removeLeadingZeros(minNum);
    }

    // Helper function to compare two strings numerically
    bool isSmaller(const string& a, const string& b) {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    }

    // Remove leading zeros
    string removeLeadingZeros(const string& str) {
        int i = 0;
        while (i < str.size() && str[i] == '0') i++;
        string res = str.substr(i);
        return res.empty() ? "0" : res;
    }
};
