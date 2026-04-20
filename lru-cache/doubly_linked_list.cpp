#include <unordered_map>

using namespace std;

// LRU Cache using a Doubly Linked List + Hash Map.
// - The doubly linked list maintains usage order:
//     HEAD <-> [MRU] <-> ... <-> [LRU] <-> TAIL
// - The hash map provides O(1) lookup by key to the corresponding list node.
// Both get and put operate in O(1) time.
class LRUCache {
public:
  // Doubly linked list node storing a key-value pair
  class Node {
  public:
    Node *prev;
    Node *next;
    int k, v; // key and value
  };

  // Maps key -> Node* for O(1) access
  unordered_map<int, Node *> mp;

  // Sentinel nodes: head (front/MRU side) and tail (back/LRU side)
  // Using sentinels eliminates edge-case checks for empty list operations
  Node *head;
  Node *tail;

  int cap; // Maximum capacity of the cache

  // Allocates and initializes a new doubly linked list node
  Node *newNode(int k, int v) {
    Node *nw = new Node();
    nw->prev = nw->next = NULL;
    nw->k = k;
    nw->v = v;
    return nw;
  }

  // Inserts 'current' immediately after the head sentinel (MRU position)
  void addNode(Node *current) {
    current->next = head->next;
    head->next->prev = current;
    head->next = current;
    current->prev = head;
  }

  // Unlinks 'current' from its current position in the list
  // Note: does NOT free the memory — caller is responsible for that
  void deleteNode(Node *current) {
    current->prev->next = current->next;
    current->next->prev = current->prev;
  }

  // Initializes the cache with dummy head and tail sentinels
  // HEAD <-> TAIL (empty cache)
  LRUCache(int capacity) {
    cap = capacity;
    head = newNode(-1, -1);
    tail = newNode(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  // Returns the value for 'key' if it exists, else -1.
  // On a cache hit, moves the accessed node to the MRU position (front).
  int get(int key) {
    if (mp.find(key) != mp.end()) {
      Node *current = mp[key];
      deleteNode(current); // Remove from current position
      addNode(current);    // Re-insert at front (MRU)
      return current->v;
    }
    return -1; // Cache miss
  }

  // Inserts or updates the key-value pair in the cache.
  // If key already exists: update and move to MRU.
  // If cache is full: evict the LRU node (just before tail) before inserting.
  void put(int key, int value) {
    // If key exists, remove the old node so we can re-insert updated one
    if (mp.find(key) != mp.end()) {
      Node *current = mp[key];
      deleteNode(current);
      mp.erase(key);
      // Note: old node memory is not freed here (potential memory leak in
      // non-LC environments)
    }

    // Evict the LRU entry if at capacity (the node just before tail)
    if (mp.size() == cap) {
      Node *lru = tail->prev; // LRU node sits just before the tail sentinel
      deleteNode(lru);
      mp.erase(lru->k);
      // Note: lru memory is not freed here (potential memory leak in non-LC
      // environments)
    }

    // Insert the new node at the MRU position (just after head)
    Node *nw = newNode(key, value);
    addNode(nw);
    mp[key] = nw; // Register in the hash map
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
