# House Robber II

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Houses are in a circle; first and last house are adjacent. Rob maximum without robbing adjacent houses.

---

## Approach: Two Linear House Robber Runs

Since first and last can't both be robbed, run House Robber I on [0..n-2] and [1..n-1] separately. Return the maximum of both results.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/house-robber-ii)
- [LeetCode](https://leetcode.com/problems/house-robber-ii/)
