/*
 * LeetCode #705 — Design HashSet
 * https://leetcode.com/problems/design-hashset/
 *
 * APPROACH: Direct Address Table (Boolean Array)
 * ──────────────────────────────────────────────────────────────
 * Given the problem constraints where keys are bounded between 0 and 1,000,000,
 * we can use a direct address table backed by a fixed-size boolean array (vector<bool>).
 * The value at index `key` represents whether `key` is present in the HashSet.
 * - `add(key)`: Set `hashSet[key] = true`.
 * - `remove(key)`: Set `hashSet[key] = false`.
 * - `contains(key)`: Return `hashSet[key]`.
 *
 * TIME  : O(1)  — Direct array indexing operations for add, remove, and contains.
 * SPACE : O(K)  — Where K is the maximum possible key value (1,000,001). C++ `std::vector<bool>` 
 *                 is space-optimized, using 1 bit per element (~125 KB total memory).
 */

#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
private:
    // Fixed-size boolean vector covering key range [0, 1000000]
    vector<bool> hashSet;

public:
    /**
     * Initializes the HashSet object with a pre-allocated boolean array.
     * Setting size to 1,000,001 allows direct indexing up to the max constraint (10^6).
     */
    MyHashSet() : hashSet(1000001, false) {
    }

    /**
     * Inserts the value key into the HashSet.
     * 
     * @param key Integer key to be added.
     */
    void add(int key) {
        // Mark index `key` as present
        hashSet[key] = true;
    }

    /**
     * Removes the value key from the HashSet if present.
     * 
     * @param key Integer key to be removed.
     */
    void remove(int key) {
        // Mark index `key` as absent
        hashSet[key] = false;
    }

    /**
     * Returns true if the set contains the specified key.
     * 
     * @param key Integer key to check.
     * @return True if key is present, false otherwise.
     */
    bool contains(int key) {
        // Direct O(1) lookup
        return hashSet[key];
    }
};

int main() {
    MyHashSet myHashSet;
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    
    cout << boolalpha;
    cout << "contains(1): " << myHashSet.contains(1) << " (Expected: true)" << endl;
    cout << "contains(3): " << myHashSet.contains(3) << " (Expected: false)" << endl;
    
    myHashSet.add(2);      // set = [1, 2]
    cout << "contains(2): " << myHashSet.contains(2) << " (Expected: true)" << endl;
    
    myHashSet.remove(2);   // set = [1]
    cout << "contains(2): " << myHashSet.contains(2) << " (Expected: false)" << endl;

    return 0;
}

/*
 * ALTERNATIVE: Chaining with Linked Lists (Bucket-based Hash Table)
 * ───────────────────────────────────────────────────────────────
 * When the range of keys is unknown or arbitrarily large, allocating a massive 
 * direct array is wasteful or impossible. We can use modular hashing with buckets 
 * (e.g. 769 prime buckets) and resolve collisions using `std::list<int>`.
 *
 *   class MyHashSet {
 *       static const int PRIME = 769;
 *       vector<list<int>> buckets;
 *       int hash(int key) { return key % PRIME; }
 *   public:
 *       MyHashSet() : buckets(PRIME) {}
 *       void add(int key) {
 *           int idx = hash(key);
 *           for (int val : buckets[idx]) if (val == key) return;
 *           buckets[idx].push_back(key);
 *       }
 *       void remove(int key) {
 *           int idx = hash(key);
 *           buckets[idx].remove(key);
 *       }
 *       bool contains(int key) {
 *           int idx = hash(key);
 *           for (int val : buckets[idx]) if (val == key) return true;
 *           return false;
 *       }
 *   };
 *
 * Trade-off vs current approach: The chaining approach handles arbitrary key ranges 
 * and scales dynamically with memory proportional to inserted elements O(N). 
 * However, lookups require traversing bucket chains (O(N/K) average, O(N) worst case), 
 * whereas the Direct Address Table provides guaranteed O(1) time operations.
 *
 * CONSTRAINT EXTENSION:
 * ──────────────────────
 * In C++, `std::vector<bool>` specializes to store 1 bit per element instead of 1 byte, 
 * making a 1,000,001 boolean array take only ~122 KB of memory. If memory limits were 
 * even stricter (e.g., 64-bit key domain), a bitset or hashing with dynamic resizing 
 * (like open addressing or linear probing) would be required.
 */
