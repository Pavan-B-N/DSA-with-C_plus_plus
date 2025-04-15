// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str);
string reverseStringUsingStack(string str);

int main()
{
    // string str="12345";
    string str = "Hello world";
    // str=reverseString(str);
    str = reverseStringUsingStack(str);
    cout << str;

    return 0;
}

string reverseString(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    return str;
}

string reverseStringUsingStack(string str)
{
    stack<char> charStack;
    for (char ch : str)
    {
        charStack.push(ch);
    }

    string reverseString = "";

    while (!charStack.empty())
    {
        reverseString += charStack.top();
        charStack.pop();
    }
    return reverseString;
}