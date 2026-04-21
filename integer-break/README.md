# Integer Break

- **Difficulty:** Medium
- **Categories:** Math, Dynamic Programming
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N)

---

Given an integer n ≥ 2, break it into at least 2 positive integers that sum to n. Maximize the product of those integers.

---

## Approach: DP or Math (Power of 3)

Mathematically: break into 3s as much as possible (and handle remainders with 2s). DP: dp[i] = max over j: max(j, dp[j]) * max(i-j, dp[i-j]).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/integer-break)
- [LeetCode](https://leetcode.com/problems/integer-break/)
