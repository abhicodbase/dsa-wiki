# Encode and Decode Strings

- **Difficulty:** Medium
- **Categories:** Array, String, Design
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Design an algorithm to encode a list of strings to a single string, and decode it back to the original list.

---

## Approach: Length-Prefix Encoding

Encode each string as its length + '#' + content (e.g., '5#hello'). Decode by reading length, then '#', then extracting that many characters.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/encode-and-decode-strings)
- [LeetCode](https://leetcode.com/problems/encode-and-decode-strings/)
