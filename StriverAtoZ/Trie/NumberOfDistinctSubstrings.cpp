// https://www.naukri.com/code360/problems/count-distinct-substrings_985292?leftPanelTabValue=PROBLEM
// Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.
/*
sds
{ ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }
ans=6
*/
#include <string>
#include <unordered_set>
using namespace std;

int countDistinctSubstrings(string &s)
{
    unordered_set<string> hashSet;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            hashSet.insert(s.substr(i, j - i + 1));
        }
    }
    return hashSet.size() + 1;
}

// O(n^2)
int countDistinctSubstrings(string &s)
{
    int count = 0;
    TrieNode *root = new TrieNode();
    // insert from i to n everytime
    for (int i = 0; i < s.size(); i++)
    {
        TrieNode *node = root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->containsKey(s[j]))
            {
                node->put(s[j]);
                count++;
            }
            node = node->get(s[j]);
        }
    }
    return count + 1;
}

class TrieNode
{
private:
    vector<TrieNode *> arr;

public:
    TrieNode()
    {
        arr.resize(26, nullptr);
    }

    bool containsKey(char ch)
    {
        int trieIndex = ch - 'a';
        return arr[trieIndex] != nullptr;
    }

    void put(char ch)
    {
        int trieIndex = ch - 'a';
        arr[trieIndex] = new TrieNode();
    }

    TrieNode *get(char ch)
    {
        int trieIndex = ch - 'a';
        return arr[trieIndex];
    }
};
