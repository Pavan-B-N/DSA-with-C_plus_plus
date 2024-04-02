/*
Convert a sentence into its equivalent mobile numeric keypad sequence
Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence

Input: GEEKSFORGEEKS
Output: 4333355777733366677743333557777

The ASCII value for 'A' is 65.
The ASCII value for 'a' is 97.

*/
#include <iostream>
using namespace std;

string printSequence(string arr[], string input)
{
    string output = "";
    int n = input.length();

    for (int i = 0; i < n; i++)
    {
        if (input[i] == ' ')
            output = output + "0";

        else
        {
            // Calculating index for each character
            int position = input[i] - 'A';
            output += arr[position];
        }
    }

    return output;
}

int main(int argc, char const *argv[])
{
    string str[] = {"2", "22", "222", "3", "33", "333", "4",
                    "44", "444", "5", "55", "555", "6", "66",
                    "666", "7", "77", "777", "7777", "8", "88",
                    "888", "9", "99", "999", "9999"};

    string input = "GEEKSFORGEEKS";
    cout << printSequence(str, input);
    return 0;
}
