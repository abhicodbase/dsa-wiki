# Ugly Number II

- **Difficulty:** Medium
- **Categories:** Hash Table, Math, Dynamic Programming, Heap
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Return the n-th ugly number (1 is the first).

---

## Approach: 3-Pointer DP

Maintain three pointers p2, p3, p5. Next ugly = min(dp[p2]×2, dp[p3]×3, dp[p5]×5). Advance all pointers that produced the minimum.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/ugly-number-ii)
- [LeetCode](https://leetcode.com/problems/ugly-number-ii/)
