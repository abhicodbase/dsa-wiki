# Smallest Divisor Given a Threshold

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(N log M)
- **Space Complexity:** O(1)

---

Find the smallest divisor such that the sum of ceil(nums[i]/divisor) for all elements is ≤ threshold.

---

## Approach: Binary Search on Divisor

Binary search divisor in [1, max(nums)]. For each divisor, compute sum of ceilings. Minimize divisor while keeping sum ≤ threshold.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/smallest-divisor-given-a-threshold)
- [LeetCode](https://leetcode.com/problems/smallest-divisor-given-a-threshold/)
