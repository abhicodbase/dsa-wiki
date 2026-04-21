# Max Consecutive Ones III

- **Difficulty:** Medium
- **Categories:** Array, Binary Search, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given a binary array and integer k, return the maximum number of consecutive 1s if you can flip at most k zeros.

---

## Approach: Sliding Window

Maintain a window with at most k zeros. Expand right; when zeros exceed k, shrink from left. The maximum window size is the answer.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/max-consecutive-ones-iii)
- [LeetCode](https://leetcode.com/problems/max-consecutive-ones-iii/)
