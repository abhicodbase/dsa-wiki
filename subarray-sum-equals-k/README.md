# Subarray Sum Equals K

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given an integer array `nums` and an integer k, return the total number of subarrays whose sum equals k.

---

## Approach: Prefix Sum + Hash Map

Maintain a running prefix sum. For each prefix sum, check how many previous prefix sums equal (currentSum - k) using a hash map. Each match represents a valid subarray.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/subarray-sum-equals-k)
- [LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/)
