#include <list>
#include <unordered_map>

using namespace std;

// LRU Cache using std::list (doubly linked list) + Hash Map.
// - std::list stores {key, value} pairs in usage order:
//     FRONT [MRU] <-> ... <-> BACK [LRU]
// - The hash map stores key -> iterator into the list for O(1) access.
// Both get and put operate in O(1) time.
class LRUCache {
public:
    // Doubly linked list of {key, value} pairs; front = MRU, back = LRU
    list<pair<int, int>> lst;

    // Maps key -> iterator into the list for O(1) node lookup and deletion
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    int length; // Maximum capacity of the cache

    // Initializes the cache with the given capacity
    LRUCache(int capacity) {
        length = capacity;
    }

    // Returns the value for 'key' if it exists in cache, else -1.
    // On a cache hit, moves the node to the front (MRU position).
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            int val = it->second;

            // Move the accessed node to front (mark as most recently used):
            // 1. Remove the node from its current position
            lst.erase(it);
            // 2. Re-insert at the front
            lst.push_front({key, val});
            // 3. Update the map to point to the new iterator
            mp[key] = lst.begin();

            return val;
        }
        return -1; // Cache miss
    }

    // Inserts or updates the key-value pair in the cache.
    // If key already exists: remove the old entry first.
    // If at capacity: evict the LRU entry (back of the list) before inserting.
    // Always inserts the new entry at the front (MRU position).
    void put(int key, int value) {
        // If key already exists, remove the stale node from the list
        // (we'll re-insert with the new value at the front)
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            lst.erase(it);
            mp.erase(key); // Also clean up the map entry
        }

        // If at capacity, evict the least recently used item (back of list)
        if (lst.size() == (size_t)length) {
            auto it = lst.back(); // LRU entry is at the back
            mp.erase(it.first);  // Remove from map
            lst.pop_back();      // Remove from list
        }

        // Insert the new entry at the front (MRU position)
        lst.push_front({key, value});
        mp[key] = lst.begin(); // Register iterator in the map
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */