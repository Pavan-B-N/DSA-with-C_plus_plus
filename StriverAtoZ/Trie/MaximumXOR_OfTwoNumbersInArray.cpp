// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Time: O(n * 2 *32 + 32) = O(n)
    // Space: O(n × 32) = O(32n) = O(n)
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        // O(32)
        trie.insert(nums[0]);
        int maxXor = 0;
        // O(n * 2 * 32)
        for (int i = 1; i < nums.size(); i++)
        {
            maxXor = max(maxXor, trie.getMax(nums[i]));
            trie.insert(nums[i]);
        }
        return maxXor;
    }
};

struct TrieNode
{
    TrieNode *links[2] = {nullptr, nullptr};

    bool containsKey(int bit) { return (links[bit] != NULL); }
    TrieNode *get(int bit) { return links[bit]; }
    void put(int bit) { links[bit] = new TrieNode(); }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie() { root = new TrieNode(); }

    // O(32)
    void insert(int num)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit);
            }
            node = node->get(bit);
        }
    }
    // O(32)
    int getMax(int num)
    {
        TrieNode *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
