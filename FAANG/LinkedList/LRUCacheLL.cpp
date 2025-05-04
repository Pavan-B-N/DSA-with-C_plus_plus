
// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
using namespace std;

class LRUCache
{
private:
    // DLL
    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };
    unordered_map<int, Node *> m;
    int limit;
    Node *head;
    Node *tail;

    void addNode(Node *newNode)
    {
        Node *oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void delNode(Node *oldNode)
    {
        Node *oldPrev = oldNode->prev;
        Node *oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

public:
    LRUCache(int capacity)
    {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *node = m[key];
            delNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int val)
    {
        if (m.find(key) != m.end())
        {
            Node *oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if (m.size() == limit)
        {
            Node *lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
        }

        Node *newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};
