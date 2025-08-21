// https://www.naukri.com/code360/problems/complete-string_2687860?leftPanelTabValue=PROBLEM
// For larger constraints or if you want a cleaner, more scalable prefix check, the Trie wins because it removes repeated work and avoids expensive substring creation.
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// Longest String with All Prefixes
// A string is called a complete string if every prefix of this string is also present in the array ‘A’. 
string completeString(int n, vector<string> &a)
{
    unordered_set<string> hashSet(a.begin(), a.end());

    string ans = "";
    for (string &str : a)
    {
        for (int j = 0; j < str.size(); j++)
        {
            string substr = str.substr(0, j + 1);
            if (!hashSet.count(substr))
            {
                break;
            }
            else if (substr.size() == ans.size() && substr < ans)
            {
                ans = substr;
            }
            else if (substr.size() > ans.size())
            {
                ans = substr;
            }
        }
    }
    return ans.empty() ? "None" : ans;
}

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

    bool isCompleteString(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch) || node->get(ch)->isEnd() == false)
            {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
};

string completeString(int n, vector<string> &a)
{
    Trie obj;
    for (string &str : a)
    {
        obj.insert(str);
    }
    string ans;
    for (string &str : a)
    {
        if (obj.isCompleteString(str))
        {
            if (str.size() > ans.size() || (str.size() == ans.size() && str < ans))
                ans = str;
        }
    }
    return ans.empty() ? "None" : ans;
}