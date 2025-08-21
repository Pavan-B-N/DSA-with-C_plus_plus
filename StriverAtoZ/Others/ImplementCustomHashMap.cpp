// Space Complexity: O(M) where M = capacity/
// With M = 10007, you’re storing 10,007 vectors, That’s not heavy at all for modern systems (few KBs).
// Average case: O(1) for put, get, remove (assuming good distribution).
// Worst case: O(n) if all keys hash to the same bucket (e.g., bad hash function, adversarial input).

// How reasonable primes help

// If you pick M = 10000 (not prime) and keys happen to all be multiples of 2 or 5, many will land in the same buckets.
// With M = 10007 (prime), collisions reduce because divisibility patterns don’t line up neatly.
// That’s why hash table sizes are often chosen as large primes.

// https://leetcode.com/problems/design-hashmap/
#include <vector>
using namespace std;

class MyHashMap
{
private:
    vector<vector<pair<int, int>>> arr;
    int CAPACITY;

    int getHash(int key) { return key % CAPACITY; }

public:
    MyHashMap()
    {
        // Prime number helps distribute keys more uniformly
        // So using 10007 (prime near 10⁴) is reasonable.
        CAPACITY = 10007; // reasonable prime bucket size
        arr.resize(CAPACITY);
    }

    void put(int key, int value)
    {
        int hash = getHash(key);
        auto &vec = arr[hash];

        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            if (it->first == key)
            {
                it->second = value; // update
                return;
            }
        }
        vec.push_back({key, value}); // insert new
    }

    int get(int key)
    {
        int hash = getHash(key);
        auto &vec = arr[hash];

        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            if (it->first == key)
            {
                return it->second;
            }
        }
        return -1; // not found
    }

    void remove(int key)
    {
        int hash = getHash(key);
        auto &vec = arr[hash];

        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            if (it->first == key)
            {
                vec.erase(it);
                break;
            }
        }
    }
};
