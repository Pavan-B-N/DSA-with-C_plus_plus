// https://leetcode.com/problems/word-ladder/
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordSet.erase(beginWord);

        while (!q.empty())
        {
            auto [word, steps] = q.front();
            q.pop();

            for (int i = 0; i < word.length(); ++i)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    word[i] = c;
                    if (word == endWord)
                        return steps + 1;

                    if (wordSet.count(word))
                    {
                        q.push({word, steps + 1});
                        wordSet.erase(word); // Mark as visited
                    }
                }
                word[i] = original;
            }
        }

        return 0; // No valid transformation sequence
    }
};
