# Reverse Nodes in k-Group

- **Difficulty:** Hard
- **Categories:** Linked List, Recursion
- **Time Complexity:** O(N)
- **Space Complexity:** O(N/K)

---

Reverse every k nodes of the linked list. If remaining nodes < k, leave them as is.

---

## Approach: Iterative Group Reversal

Count k nodes ahead to verify a full group exists. Reverse those k nodes using standard reversal. Connect with previous group's tail and move to next group.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/reverse-nodes-in-k-group)
- [LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/)
