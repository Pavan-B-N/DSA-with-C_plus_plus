// https://leetcode.com/problems/word-ladder-ii/
// https://www.geeksforgeeks.org/problems/word-ladder-ii/1
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// LeetCode Memory limit: its not working on leetcode because it requires cp to reduce memory usage
// but works in GFG
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;

        unordered_set<string> hashSet(wordList.begin(), wordList.end());
        if (!hashSet.count(endWord))
            return ans; // endWord not in list → return {}

        queue<vector<string>> q;
        q.push({beginWord});

        bool found = false; // stop BFS after first level reaching endWord

        while (!q.empty() && !found)
        {
            int levelSize = q.size();
            unordered_set<string> usedOnLevel;

            for (int i = 0; i < levelSize; i++)
            {
                auto vec = q.front();
                string word = vec.back();
                q.pop();

                for (int j = 0; j < word.size(); j++)
                {
                    char originalChar = word[j];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[j] = ch;

                        if (hashSet.count(word))
                        {
                            vec.push_back(word);
                            if (word == endWord)
                            {
                                found = true;
                                ans.push_back(vec);
                            }
                            else
                            {
                                q.push(vec);
                            }
                            vec.pop_back();
                            usedOnLevel.insert(word);
                        }
                    }
                    word[j] = originalChar;
                }
            }

            for (auto &w : usedOnLevel)
                hashSet.erase(w);
        }

        return ans;
    }
};
