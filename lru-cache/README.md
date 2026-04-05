# LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

### Complexity
- **Time Complexity**: O(1) for both get and put
- **Space Complexity**: O(capacity)

---
### Approach
Use a combination of a hash map and a doubly linked list. The hash map provides O(1) access to nodes, and the doubly linked list maintains the order of usage.
