# Number of Substrings Containing All Three Characters

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Count substrings of string s (only 'a', 'b', 'c') that contain at least one of each.

---

## Approach: Sliding Window (Shrink to Find Boundary)

Maintain last-seen index for each character. For each right pointer, the count of valid substrings ending at right = min(last_a, last_b, last_c) + 1.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/number-of-substrings-containing-all-three-characters)
- [LeetCode](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)
