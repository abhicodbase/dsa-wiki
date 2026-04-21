# Palindrome Partitioning II

- **Difficulty:** Hard
- **Categories:** String, Dynamic Programming
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N²)

---

Given a string s, partition it so every substring is a palindrome. Return the minimum number of cuts needed.

---

## Approach: DP with Palindrome Precomputation

Precompute isPalin[i][j]. dp[i] = min cuts for s[0..i]. dp[i] = 0 if s[0..i] is palindrome; else min over j≤i where s[j..i] is palindrome: dp[j-1]+1.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/palindrome-partitioning-ii)
- [LeetCode](https://leetcode.com/problems/palindrome-partitioning-ii/)
