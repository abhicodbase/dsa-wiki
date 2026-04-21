# Copy List with Random Pointer

- **Difficulty:** Medium
- **Categories:** Hash Table, Linked List
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Deep copy a linked list where each node has a next pointer and a random pointer pointing to any node or null.

---

## Approach: Hash Map (Old Node → New Node)

First pass: create all new nodes and store old→new mapping in a hash map. Second pass: set next and random pointers of each new node using the map.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/copy-list-with-random-pointer)
- [LeetCode](https://leetcode.com/problems/copy-list-with-random-pointer/)
