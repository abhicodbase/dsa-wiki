# Find All Duplicates in an Array

- **Difficulty:** Medium
- **Categories:** Array, Hash Table
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an integer array `nums` of length n where all integers are in range [1, n], return all duplicates.

---

## Approach: Index as Hash (Negation trick)

For each value v, negate nums[v-1]. If nums[v-1] is already negative, v is a duplicate. This achieves O(1) extra space.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-all-duplicates-in-an-array)
- [LeetCode](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
