// https://leetcode.com/problems/word-ladder/
/*
transformation sequence from word beginWord to word endWord using a dictionary wordList

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// O(N×L×26)=O(N×L)
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) // we can also make use of find method
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
                word[i] = original;// IMP to backtrack
            }
        }

        return 0; // No valid transformation sequence
    }
};

// brute force , TLE
// 🔸 Because we must try many permutations of wordList (different orderings of transformations),
// 🔸 And because the remaining word set changes with each path,
// 🔸 We don't get repeated subproblems, so DP isn't effective.
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        int result = getLadderLength(beginWord, endWord, wordSet);
        return result == INT_MAX ? 0 : result;
    }

    // O(N!×26×L)=O(N!×L)
    // O(N!×L)
    // N is the number of words in wordList
    // L is the length of beginWord word (fixed)
    // N! → Because in the worst case, you could explore all permutations of N words
    int getLadderLength(string beginWord, string &endWord, unordered_set<string> &s)
    {
        if (beginWord == endWord)
            return 1;

        int minSteps = INT_MAX;

        for (int i = 0; i < beginWord.length(); i++)
        {
            char originalChar = beginWord[i];

            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == originalChar)
                    continue;

                beginWord[i] = c;

                if (s.find(beginWord) != s.end())
                {
                    string nextWord = beginWord;
                    s.erase(nextWord); // mark visited

                    int steps = getLadderLength(nextWord, endWord, s);
                    if (steps != INT_MAX)
                    {
                        minSteps = min(minSteps, 1 + steps);
                    }

                    s.insert(nextWord); // backtrack
                }
            }

            beginWord[i] = originalChar; // restore
        }

        return minSteps;
    }
};