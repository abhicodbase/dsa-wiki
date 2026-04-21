# Linked List Random Node

- **Difficulty:** Medium
- **Categories:** Linked List, Math, Randomized
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given a singly linked list, return a uniformly random node's value. Unknown list length. O(1) space.

---

## Approach: Reservoir Sampling

Reservoir sampling of size 1: for i-th node, replace reservoir with probability 1/i. Final reservoir contains a uniformly random node value.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/linked-list-random-node)
- [LeetCode](https://leetcode.com/problems/linked-list-random-node/)
