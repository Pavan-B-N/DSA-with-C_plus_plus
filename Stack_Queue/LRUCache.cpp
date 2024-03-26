/*
Cache replacement algorithms are efficiently designed to replace the cache when the space is full. The Least Recently Used (LRU) is one of those algorithms
LRU picks the data that is least recently used and removes it in order to make space for the new data.

Operations on LRU Cache:
1. LRUCache (Capacity c): Initialize LRU cache with positive size capacity c.
2. get (key): Returns the value of Key ‘k’ if it is present in the cache otherwise it returns -1. Also updates the priority of data in the LRU cache.
3. put (key, value): Update the value of the key if that key exists, Otherwise, add key-value pair to the cache. If the number of keys exceeded the capacity of LRU cache then dismiss the least recently used key


*/
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

class LRUCache {
private:
    unordered_map<int, int> cache; // Key-value storage
    deque<int> recentKeys; // Queue to maintain most recent keys
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // Check if key exists in cache
        if (cache.find(key) != cache.end()) {
            // Move the key to the front of the queue to indicate it's most recent
            recentKeys.erase(remove(recentKeys.begin(), recentKeys.end(), key), recentKeys.end());
            recentKeys.push_front(key);
            return cache[key]; // Return the value
        }
        return -1; // Key not found
    }

    void put(int key, int value) {
        // If key already exists, update its value and move it to the front
        if (cache.find(key) != cache.end()) {
            recentKeys.erase(remove(recentKeys.begin(), recentKeys.end(), key), recentKeys.end());
        } else if (cache.size() >= capacity) {
            int leastRecent = recentKeys.back(); // Evict the least recent key
            recentKeys.pop_back();
            cache.erase(leastRecent);
        }
        recentKeys.push_front(key);
        cache[key] = value; // Update cache with new value
    }
};

int main() {
    // Create an LRU cache with capacity 2
    LRUCache cache(2);

    // Inserting key-value pairs
    cache.put(1, 1);
    cache.put(2, 2);

    // Retrieving the value for key 1
    cout << cache.get(1) << endl; // Output: 1

    // Inserting another key-value pair, which will evict key 2
    cache.put(3, 3);

    // Retrieving the value for key 2, which should return -1 as it's evicted
    cout << cache.get(2) << endl; // Output: -1

    return 0;
}
