# Decode String

- **Difficulty:** Medium
- **Categories:** String, Stack, Recursion
- **Time Complexity:** O(max_k × N)
- **Space Complexity:** O(N)

---

Given an encoded string like '3[a2[bc]]', decode it to 'abcbcabcbcabcbc'.

---

## Approach: Stack of (count, built_string)

Use a stack of (repeat_count, current_string). On '[': push current state. On ']': pop, multiply inner string by count, append to outer. Accumulate digits and chars.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/decode-string)
- [LeetCode](https://leetcode.com/problems/decode-string/)
