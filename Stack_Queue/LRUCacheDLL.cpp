#include <iostream>
#include <unordered_map>

using namespace std;
// using doubly linked list and hashing

// Node for the doubly linked list
class DoubleLinkedListNode {
public:
    int key;
    int value;
    DoubleLinkedListNode* prev;
    DoubleLinkedListNode* next;

    DoubleLinkedListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// LRUCache class
class LRUCache {
private:
    unordered_map<int, DoubleLinkedListNode*> cache;
    DoubleLinkedListNode* head;
    DoubleLinkedListNode* tail;
    int capacity;

    // Move a node to the front of the list
    void moveToHead(DoubleLinkedListNode* node) {
        if (node == head) return;

        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = nullptr;
        node->next = head;
        head->prev = node;
        head = node;
    }

public:
    // Constructor
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

    // Destructor
    ~LRUCache() {
        for (auto it = cache.begin(); it != cache.end(); ++it)
            delete it->second;
    }

    // Get the value from the cache, move the node to the front
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1; // Not found
        DoubleLinkedListNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    // Put the value into the cache
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) { // Key exists
            cache[key]->value = value;
            moveToHead(cache[key]);
        } else {
            DoubleLinkedListNode* newNode = new DoubleLinkedListNode(key, value);
            cache[key] = newNode;

            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            if (cache.size() > capacity) {
                cache.erase(tail->key);
                DoubleLinkedListNode* temp = tail->prev;
                delete tail;
                tail = temp;
                if (tail) tail->next = nullptr;
            }
        }
    }

    // Print cache content
    void printCache() {
        DoubleLinkedListNode* current = head;
        while (current) {
            cout << "(" << current->key << ", " << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.printCache(); // Output: (2, 2) (1, 1)

    cout << "Value of key 1: " << cache.get(1) << endl; // Output: Value of key 1: 1
    cache.printCache(); // Output: (1, 1) (2, 2)

    cache.put(3, 3);
    cache.printCache(); // Output: (3, 3) (1, 1)

    cout << "Value of key 2: " << cache.get(2) << endl; // Output: Value of key 2: -1 (not found)

    return 0;
}
