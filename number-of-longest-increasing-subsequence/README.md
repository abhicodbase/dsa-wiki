# Number of Longest Increasing Subsequence

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Binary Indexed Tree, Segment Tree
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N)

---

Given an integer array, return the number of longest increasing subsequences.

---

## Approach: DP with Length and Count Arrays

Maintain dp_len[i] = LIS length ending at i, dp_cnt[i] = number of such LIS. For each j < i with nums[j] < nums[i]: if dp_len[j]+1 > dp_len[i], update length and reset count; if equal, add count.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/number-of-longest-increasing-subsequence)
- [LeetCode](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
