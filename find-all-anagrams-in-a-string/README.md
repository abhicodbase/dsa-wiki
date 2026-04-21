# Find All Anagrams in a String

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given strings s and p, return all start indices of p's anagrams in s.

---

## Approach: Sliding Window with Frequency Matching

Use a fixed window of size len(p). Maintain counts of characters needed. When needed count is 0, all characters are matched — record the start index.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-all-anagrams-in-a-string)
- [LeetCode](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
