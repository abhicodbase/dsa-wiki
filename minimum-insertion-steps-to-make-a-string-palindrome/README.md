# Minimum Insertion Steps to Make a String Palindrome

- **Difficulty:** Hard
- **Categories:** String, Dynamic Programming
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N²)

---

Find the minimum number of insertions needed to make a string a palindrome.

---

## Approach: LCS of s and Reverse(s)

min insertions = n - LCS(s, reverse(s)). Characters not in the LCS need to be mirrored by inserting their counterparts. Standard LCS DP.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-insertion-steps-to-make-a-string-palindrome)
- [LeetCode](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)
