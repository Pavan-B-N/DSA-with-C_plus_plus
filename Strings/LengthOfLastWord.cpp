#include <iostream>
#include <string>
using namespace std;

void trim(string &str)
{
    bool inWord = false;
    int index = 0;
    for (char ch : str)
    {
        if (ch != ' ')
        {
            str[index++] = ch;
            inWord = true;
        }
        else if (inWord)
        {
            str[index++] = ' ';
            inWord = false;
        }
    }
    // handling trailing whitespaces
    if (str[index - 1] == ' ')
    {
        index--;
    }
    // Resize the string to remove any characters beyond index
    str.resize(index);
    // In C++, std::string objects are not null-terminated like C-style strings
}

int lengthOfLastWord(string s)
{
    // trim
    trim(s);
    cout << s << "END" << endl;
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            cout << len << " ";
            len = 0;
        }
        else
        {
            len++;
        }
    }
    return len;
}