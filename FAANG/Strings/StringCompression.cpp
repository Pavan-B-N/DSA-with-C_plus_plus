// https://leetcode.com/problems/string-compression/
/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
*/
#include <vector>
#include <string>
using namespace std;
int compress(vector<char>& chars) {
    int arrlen = 0;
    for (int i = 0; i < chars.size(); i++) {
        int count = 1;
        // count duplicates
        while (i + 1 < chars.size() && chars[i] == chars[i + 1]) {
            count++;
            i++;
        }
        chars[arrlen++] = chars[i];
        if (count > 1) {
            // this can work only for 0-9 digits i.e for only single digits
            //  chars[arrlen++] = count+'0';
            string cntStr = to_string(count); // convert count to string
            for (char c : cntStr) {
                chars[arrlen++] = c; // add each digit
            }
        }
    }
    chars.resize(arrlen);
    return arrlen;
}