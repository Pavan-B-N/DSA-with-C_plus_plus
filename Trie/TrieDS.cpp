#include <iostream>
#include <vector>
using namespace std;

// TrieNode class represents each node in the Trie
class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr); // Initialize children array with nullptr
        isWord = false;
    }
};

// Trie class represents the Trie data structure
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = getIndex(ch);
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }

    // Function to list all words in the Trie
    void listAll() {
        listAll(root, "");
    }

    void listAll(TrieNode* node, string prefix) {
        if (node->isWord) {
            cout << prefix << endl;
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char ch = 'a' + i;
                listAll(node->children[i], prefix + ch);
            }
        }
    }

    // Function to search for words starting with a prefix
    void startsWith(string prefix) {
        startsWith(root, prefix, "");
    }

    void startsWith(TrieNode* node, string prefix, string currentPrefix) {
        if (prefix.empty()) {
            listAll(node, currentPrefix);
            return;
        }
        char ch = prefix[0];
        int index = getIndex(ch);
        TrieNode* currentNode = node->children[index];
        if (currentNode == nullptr) {
            return;
        }
        startsWith(currentNode, prefix.substr(1), currentPrefix + ch);
    }

private:
    // Function to get index of character
    int getIndex(char ch) {
        return ch - 'a';
    }
};

int main() {
    Trie dict;

    dict.insert("dog");
    dict.insert("doll");
    dict.insert("do");
    dict.insert("son");
    dict.insert("so");

    // dict.listAll();

    dict.startsWith("s");

    return 0;
}
