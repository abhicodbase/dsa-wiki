# Remove Nth Node From End of List

- **Difficulty:** Medium
- **Categories:** Linked List, Two Pointers
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given the head of a linked list, remove the n-th node from the end and return the head.

---

## Approach: Two-Pointer Gap Technique

Advance fast pointer n+1 steps. Then move both fast and slow together until fast reaches null. Slow is now at the node before the one to delete.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/remove-nth-node-from-end-of-list)
- [LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
