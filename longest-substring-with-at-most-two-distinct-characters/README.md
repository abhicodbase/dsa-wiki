# Longest Substring with At Most Two Distinct Characters

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Find the length of the longest substring that contains at most two distinct characters.

---

## Approach: Sliding Window with Frequency Map

Maintain a window with at most 2 distinct characters using a frequency map. When the map exceeds 2 keys, shrink from the left until 2 or fewer remain.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/longest-substring-with-at-most-two-distinct-characters)
- [LeetCode](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
