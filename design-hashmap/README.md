# Design HashMap

- **Difficulty:** Easy
- **Categories:** Array, Hash Table, Linked List, Design, Hash Function
- **Time Complexity:** O(1) avg
- **Space Complexity:** O(N)

---

Design a HashMap from scratch with put(key, val), get(key), remove(key). No built-in hash table libraries.

---

## Approach: Array of Buckets with Chaining

Use a fixed-size array. Hash key to bucket index. Each bucket is a linked list (for collision handling). Operations traverse the bucket's list.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/design-hashmap)
- [LeetCode](https://leetcode.com/problems/design-hashmap/)
