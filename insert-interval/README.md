# Insert Interval

- **Difficulty:** Medium
- **Categories:** Array
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given a sorted non-overlapping list of intervals and a new interval, insert it in sorted order and merge if necessary. Return the updated list.

---

## Approach: Linear Scan & Merge

Add all intervals ending before newInterval starts. Merge all overlapping intervals with newInterval. Then append all remaining intervals.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/insert-interval)
- [LeetCode](https://leetcode.com/problems/insert-interval/)
