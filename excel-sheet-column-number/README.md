# Excel Sheet Column Number

- **Difficulty:** Easy
- **Categories:** Math, String
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given a column title (like 'AB'), return its corresponding column number.

---

## Approach: Base-26 Conversion

Process characters left to right. result = result*26 + (char - 'A' + 1). Similar to base-10 string-to-integer conversion.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/excel-sheet-column-number)
- [LeetCode](https://leetcode.com/problems/excel-sheet-column-number/)
