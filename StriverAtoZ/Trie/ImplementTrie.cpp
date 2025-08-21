// https://leetcode.com/problems/implement-trie-prefix-tree/description/
// ImplementTrieOptimal.cpp
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> arr;
    bool flag;
    TrieNode()
    {
        arr.resize(26, nullptr); // 26 lowercase English letters
        flag = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int trieIndex = ch - 'a';
            if (node->arr[trieIndex] == nullptr)
            {
                node->arr[trieIndex] = new TrieNode();
            }
            node = node->arr[trieIndex];
        }
        node->flag = true; // mark end of word
    }

    bool search(string word)
    {
        TrieNode *node = root;

        for (char ch : word)
        {
            int trieIndex = ch - 'a';
            if (node->arr[trieIndex] == nullptr)
            {
                return false;
            }
            node = node->arr[trieIndex];
        }
        return node->flag;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;

        for (char ch : prefix)
        {
            int trieIndex = ch - 'a';
            if (node->arr[trieIndex] == nullptr)
            {
                return false;
            }
            node = node->arr[trieIndex];
        }
        return true;
    }
};
