#include <unordered_map>
using namespace std;
// https://leetcode.com/problems/lru-cache/
class LRUCache
{
private:
    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;

        Node(int _key, int _val)
            : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

    int CAPACITY;
    unordered_map<int, Node *> map;
    Node *head; // Most recently used
    Node *tail; // Least recently used

    // Removes a node from the linked list
    void removeNode(Node *node)
    {

        if (node == head)
        {
            head = head->next;
        }
        else if (node == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = nullptr;
        node->next = nullptr;
    }

    // Inserts a node at the front (most recently used)
    void insertAtFront(Node *newNode)
    {
        newNode->next = head;

        if (head)
            head->prev = newNode;
        head = newNode;

        if (!tail)
            tail = newNode; // First insertion
    }

    // Move a node to the front
    void moveToFront(Node *node)
    {
        removeNode(node);
        insertAtFront(node);
    }

public:
    LRUCache(int capacity)
    {
        CAPACITY = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;

        Node *node = map[key];
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            // Update existing value and move to front
            Node *node = map[key];
            node->val = value;
            moveToFront(node);
        }
        else
        {
            // Insert new node
            Node *newNode = new Node(key, value);
            insertAtFront(newNode);
            map[key] = newNode;

            // Evict LRU if at capacity
            if ((int)map.size() > CAPACITY)
            {
                Node *lru = tail;
                map.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
        }
    }
};
