# Boats to Save People

- **Difficulty:** Medium
- **Categories:** Array, Two Pointers, Greedy, Sorting
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(1)

---

Each boat carries at most 2 people with a weight limit. Find minimum boats needed.

---

## Approach: Two Pointer Greedy on Sorted Array

Sort. Use two pointers (lightest and heaviest). If their weights sum <= limit, both fit in one boat. Otherwise, heaviest goes alone. Either way, decrement right; if paired, increment left.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/boats-to-save-people)
- [LeetCode](https://leetcode.com/problems/boats-to-save-people/)
