# Counting Bits

- **Difficulty:** Easy
- **Categories:** Dynamic Programming, Bit Manipulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given an integer n, return an array of length n+1 where ans[i] is the number of 1s in the binary representation of i.

---

## Approach: DP with Bit Shift

dp[i] = dp[i >> 1] + (i & 1). Each number has the same bits as half of it, plus possibly 1 more if odd.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/counting-bits)
- [LeetCode](https://leetcode.com/problems/counting-bits/)
