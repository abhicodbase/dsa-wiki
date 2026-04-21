# Add Two Numbers

- **Difficulty:** Medium
- **Categories:** Linked List, Math, Recursion
- **Time Complexity:** O(max(M,N))
- **Space Complexity:** O(max(M,N))

---

Two non-empty linked lists represent two non-negative integers in reverse order. Add and return the sum as a linked list.

---

## Approach: Digit-by-Digit Addition with Carry

Traverse both lists simultaneously, adding corresponding digits and carry. Create a new node for each digit sum % 10. Propagate carry until both lists are exhausted.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/add-two-numbers)
- [LeetCode](https://leetcode.com/problems/add-two-numbers/)
