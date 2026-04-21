# Integer to Roman

- **Difficulty:** Medium
- **Categories:** Hash Table, Math, String
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Convert an integer in range [1, 3999] to its Roman numeral representation.

---

## Approach: Greedy with Value-Symbol Table

Create a sorted list of (value, symbol) pairs in descending order. Greedily subtract the largest value fitting into num and append the symbol to result.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/integer-to-roman)
- [LeetCode](https://leetcode.com/problems/integer-to-roman/)
