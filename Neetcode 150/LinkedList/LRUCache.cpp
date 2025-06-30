// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
using namespace std;

class LRUCache {
private:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int _key, int _val)
            : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

    int CAPACITY;
    unordered_map<int, Node*> map;
    Node* head; // Most recently used
    Node* tail; // Least recently used

    // Removes a node from the linked list
    void removeNode(Node* node) {
        if (!node)
            return;

        if (node->prev)
            node->prev->next = node->next;
        else
            head = node->next;

        if (node->next)
            node->next->prev = node->prev;
        else
            tail = node->prev;

        node->prev = nullptr;
        node->next = nullptr;
    }

    // Inserts a node at the front (most recently used)
    void insertAtFront(Node* node) {
        node->next = head;

        if (head)
            head->prev = node;
        head = node;

        if (!tail)
            tail = head; // First insertion
    }

    // Move a node to the front
    void moveToFront(Node* node) {
        removeNode(node);
        insertAtFront(node);
    }

public:
    LRUCache(int capacity) {
        CAPACITY = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;

        Node* node = map[key];
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Update existing value and move to front
            Node* node = map[key];
            node->val = value;
            moveToFront(node);
        } else {
            // Evict LRU if at capacity
            if ((int)map.size() == CAPACITY) {
                Node* lru = tail;
                map.erase(lru->key);
                removeNode(lru);
                delete lru;
            }

            // Insert new node
            Node* newNode = new Node(key, value);
            insertAtFront(newNode);
            map[key] = newNode;
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
