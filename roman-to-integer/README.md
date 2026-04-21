# Roman to Integer

- **Difficulty:** Easy
- **Categories:** Hash Table, Math, String
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Convert a Roman numeral string to its integer value.

---

## Approach: Right-to-Left Scan

Map each Roman numeral to its value. Traverse right to left: if the current value is less than the previous, subtract it; otherwise add it.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/roman-to-integer)
- [LeetCode](https://leetcode.com/problems/roman-to-integer/)
