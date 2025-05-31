/*
You are given a sorted dictionary of an alien language that uses the English alphabet. The dictionary is sorted lexicographically (i.e., words are in dictionary order) but the order of characters is unknown.

Your task is to find the order of characters in the alien language.

N: An integer representing the number of words in the dictionary.
K: An integer representing the total number of unique characters in the alien language (assume they are all lowercase English letters).
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// https://www.geeksforgeeks.org/problems/alien-dictionary/1
class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> adj(26);     // adjacency list
        vector<int> indegree(26, 0);     // indegree for each character
        vector<bool> present(26, false); // mark characters that are present

        // Step 1: Mark present characters
        for (const string &word : words)
        {
            for (char ch : word)
            {
                present[ch - 'a'] = true;
            }
        }

        // Step 2: Build the adjacency list
        for (int i = 0; i < n - 1; i++)
        {
            string &s1 = words[i];
            string &s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            // Invalid case: word1 longer and word2 is prefix
            if (s1.size() > s2.size() && s1.substr(0, len) == s2.substr(0, len))
            {
                return "";
            }

            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indegree[s2[j] - 'a']++;
                    break;
                }
            }
        }

        // Step 3: Topological Sort using Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (present[i] && indegree[i] == 0)
            {
                q.push(i);
            }
        }

        string result;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result += (char)(u + 'a');

            for (int v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // Check for cycle or incomplete order
        int uniqueCount = count(present.begin(), present.end(), true);
        if (result.size() != uniqueCount)
            return "";

        return result;
    }
};
