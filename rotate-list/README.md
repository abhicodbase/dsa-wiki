# Rotate List

- **Difficulty:** Medium
- **Categories:** Linked List, Two Pointers
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given the head of a linked list, rotate the list to the right by k places.

---

## Approach: Form a Cycle and Break

Find length N. Set k = k % N. Connect tail to head forming a cycle. Break the cycle at position N-k from the start to get the new head.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/rotate-list)
- [LeetCode](https://leetcode.com/problems/rotate-list/)
