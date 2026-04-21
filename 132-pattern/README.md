# 132 Pattern

- **Difficulty:** Medium
- **Categories:** Array, Binary Search, Stack, Monotonic Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find if there exists a 132 pattern (nums[i] < nums[k] < nums[j], i < j < k).

---

## Approach: Monotonic Stack + Track Min

Traverse right to left. Maintain a stack and a 'third' value (the '2' in 132). Pop elements smaller than current onto 'third'. If current < 'third', 132 pattern found.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/132-pattern)
- [LeetCode](https://leetcode.com/problems/132-pattern/)
