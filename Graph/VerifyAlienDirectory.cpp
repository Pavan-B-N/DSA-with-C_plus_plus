// https://leetcode.com/problems/verifying-an-alien-dictionary/description/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Map each character to its position in the alien dictionary
        vector<int> pos(26);
        for (int i = 0; i < order.size(); ++i) {
            pos[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool diffFound = false;

            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (pos[w1[j] - 'a'] > pos[w2[j] - 'a'])
                        return false;
                    diffFound = true;
                    break;
                }
            }

            // If all characters are the same but one word is longer
            if (!diffFound && w1.length() > w2.length())
                return false;
        }

        return true;
    }
};