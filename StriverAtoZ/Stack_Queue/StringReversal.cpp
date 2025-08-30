#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverse(string &str)
{
    stack<char> charStack;

    for (char ch : str)
    {
        charStack.push(ch);
    }

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = charStack.top();
        charStack.pop();
    }
}

int main()
{
    string str = "Hello";
    cout << str << endl;

    reverse(str);

    cout << str << endl;

    return 0;
}
