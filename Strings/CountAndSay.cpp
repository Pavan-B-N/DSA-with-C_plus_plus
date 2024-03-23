// https://leetcode.com/problems/count-and-say/description/
/*
sequence-generation problem.
1 is read as "one 1" or 11.
11 is read as "two 1s" or 21.
21 is read as "one 2, then one 1" or 1211.
1211 is read as "one 1, one 2, then two 1s" or 111221.
111221 is read as "three 1s, two 2s, then one 1" or 312211.

Given an integer n where 1 ≤ n ≤ 30, generate the n-th term of the count-and-say sequence.

Example:

Input: n = 4
Output: "1211"
Explanation: The sequence is "1", "11", "21", "1211", ....
*/

#include <iostream>
#include <string>
using namespace std;

void countAndSayNumber(int n) {
    string str = "1";
    cout << str << endl;
    while (n > 1) {
        int count = 1;
        string temp = "";
        for (int i = 0; i < str.length(); i++) {
            if (i < str.length() - 1 && str[i] == str[i + 1]) {
                count++;
            } else {
                temp += to_string(count);
                temp += str[i];
                count = 1; // Reset count
            }
        }
        // Update str with the new term
        str = temp;
        cout << str << endl;
        n--;
    }
}

int main() {
    int n =4;
    cout<<"Enter n: ";
    cin>>n;
    countAndSayNumber(n);
    return 0;
}
