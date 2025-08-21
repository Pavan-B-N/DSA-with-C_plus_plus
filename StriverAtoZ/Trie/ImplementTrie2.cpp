// https://www.naukri.com/code360/problems/implement-trie_1387095
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> arr;
    int countEndsWith;
    int countPrefix;

    TrieNode()
    {
        arr.resize(26, nullptr);
        countEndsWith = 0;
        countPrefix = 0;
    }

    bool containsKey(char ch)
    {
        return arr[ch - 'a'] != nullptr;
    }

    void put(char ch)
    {
        arr[ch - 'a'] = new TrieNode();
    }

    TrieNode *get(char ch)
    {
        return arr[ch - 'a'];
    }

    void incrementCountPrefix() { countPrefix++; }
    void incrementEndsWith() { countEndsWith++; }
    void decrementCountPrefix() { countPrefix--; }
    void decrementEndsWith() { countEndsWith--; }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch);
            }
            node = node->get(ch);
            node->incrementCountPrefix();
        }
        node->incrementEndsWith();
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->countEndsWith;
    }

    int countWordsStartingWith(string &prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->countPrefix;
    }

    void erase(string &word)
    {
        // optional: its guranted that erase will be called for the existing words only
        if (countWordsEqualTo(word) == 0)
            return;
        TrieNode *node = root;
        for (char ch : word)
        {
            node = node->get(ch);
            node->decrementCountPrefix();
        }
        node->decrementEndsWith();
    }
};
