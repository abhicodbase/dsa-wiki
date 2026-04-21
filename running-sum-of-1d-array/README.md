# Running Sum of 1d Array

- **Difficulty:** Easy
- **Categories:** Array, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an array nums, return the running sum: runningSum[i] = sum(nums[0]...nums[i]).

---

## Approach: In-Place Prefix Sum

Accumulate: for i from 1 to n-1, nums[i] += nums[i-1]. The array becomes its own prefix sum in O(1) extra space.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/running-sum-of-1d-array)
- [LeetCode](https://leetcode.com/problems/running-sum-of-1d-array/)
