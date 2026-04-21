# Missing Number

- **Difficulty:** Easy
- **Categories:** Array, Math, Bit Manipulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an array containing n distinct numbers in range [0, n], return the only number in the range that is missing.

---

## Approach: Gauss Sum / XOR

Expected sum = n*(n+1)/2. Subtract actual sum to get the missing number. Alternatively XOR all indices and all values; the result is the missing number.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/missing-number)
- [LeetCode](https://leetcode.com/problems/missing-number/)
