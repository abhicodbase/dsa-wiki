# Find Pivot Index

- **Difficulty:** Easy
- **Categories:** Array, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Find the pivot index where the sum of all elements to the left equals the sum to the right.

---

## Approach: Total Sum - Left Sum

Compute total sum. Iterate: leftSum tracks sum of elements before i. If leftSum == totalSum - leftSum - nums[i], return i. Increment leftSum.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-pivot-index)
- [LeetCode](https://leetcode.com/problems/find-pivot-index/)
