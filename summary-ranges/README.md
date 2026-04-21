# Summary Ranges

- **Difficulty:** Easy
- **Categories:** Array
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given a sorted unique integer array, return the smallest sorted list of ranges that cover all numbers exactly.

---

## Approach: Linear Scan

Iterate through the array tracking start of current range. When a gap is found (nums[i] != nums[i-1]+1), close the current range, add to result, and start a new range.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/summary-ranges)
- [LeetCode](https://leetcode.com/problems/summary-ranges/)
