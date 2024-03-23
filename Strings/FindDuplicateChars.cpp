/*
Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

input: S = “geeksforgeeks”
Output:

e, count = 4
g, count = 2
k, count = 2
s, count = 2
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// using hashing
// Time Complexity: O(N)
// Auxiliary Space: O(K), where K = size of the map (0<=K<=input_string_length), in worst case space will be O(N).
void findDuplicateChars(string str){
    unordered_map<char,int> hashMap;

    // Count occurrences of each character in the string
    for (char c : str) {
        hashMap[c]++;
    }

    // Print duplicate characters
    cout << "Duplicate characters in the string '" << str << "': \n";
    for (auto pair : hashMap) {
        if (pair.second > 1) {
            cout << pair.first << " "<< pair.second <<endl;;
        }
    }
}
// using sorting technique
// Time Complexity: O(N*logN)
// Auxiliary Space: O(1)
void printDuplicates(string str)
{
    int len = str.length();
 
    // Sorting the string
    sort(str.begin(), str.end());
 
    // Loop through the sorted string to find duplicates
    for (int i = 0; i < len; i++) {
        int count = 1;
 
        // Counting the occurrences of each character
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
 
        // Printing the duplicate character and its count
        if (count > 1) {
            cout << str[i] << ", count = " << count << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string str="geeksforgeeks";
    findDuplicateChars(str);
    return 0;
}
