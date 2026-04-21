# Triangle

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N)

---

Given a triangle array, find the minimum path sum from top to bottom (moving to adjacent numbers in the row below).

---

## Approach: Bottom-Up DP (In-Place)

Start from second-to-last row, going up. dp[j] += min(dp[j], dp[j+1]). Work from bottom row upward — the answer is dp[0] at the top.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/triangle)
- [LeetCode](https://leetcode.com/problems/triangle/)
