/*
a valid shuffle means that the characters from str1 and str2 are taken in a continuous order in the resulting string result, and the relative order of characters from str1 and str2 is maintained.

For example, if str1 = "abc" and str2 = "def", 
a valid shuffle of str1 and str2 could be "adbecf". In this shuffle:

*/

#include <iostream>
#include <string>

using namespace std;

bool isValidShuffle(const string& str1, const string& str2, const string& result) {
    int len1 = str1.length();
    int len2 = str2.length();
    int lenResult = result.length();

    if (lenResult != len1 + len2)
        return false;

    int i = 0, j = 0, k = 0;

    while (k < lenResult) {
        if (i < len1 && result[k] == str1[i])
            i++;
        else if (j < len2 && result[k] == str2[j])
            j++;
        else
            return false;
        k++;
    }
    return (i == len1 && j == len2);
}

int main() {
    string str1 = "abc";
    string str2 = "def";
    string result = "adbecf";

    if (isValidShuffle(str1, str2, result))
        cout << "Valid Shuffle" << endl;
    else
        cout << "Invalid Shuffle" << endl;

    return 0;
}
