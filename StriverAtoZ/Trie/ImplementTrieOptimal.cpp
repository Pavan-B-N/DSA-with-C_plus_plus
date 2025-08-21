// https://leetcode.com/problems/implement-trie-prefix-tree/description/
#include <vector>
#include <string>
using namespace std;

// Time complexity for each operation: O(len)
class TrieNode
{
private:
    vector<TrieNode *> arr;
    bool flag;

public:
    TrieNode()
    {
        flag = false;
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

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};
