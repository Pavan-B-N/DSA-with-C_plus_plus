#include <iostream>
#include <vector>
using namespace std;

string reverseWords(string s)
{
    vector<string> arr;
    string word = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (word != "" && word != " ")
                arr.push_back(word);
            word = "";
            continue;
        }
        word += s[i];
    }
    if (word != "" && word != " ")
        arr.push_back(word);

    string str = "";
    for (int i = (arr.size() - 1); i > 0; i--)
    {
        str += arr[i];
        str += " ";
    }
    // Add the last word without the trailing space
    str += arr[0];
    return str;
}

int main()
{
    string str = "    the sky is   blue ";
    str = reverseWords(str);
    cout << str;
    return 0;
}