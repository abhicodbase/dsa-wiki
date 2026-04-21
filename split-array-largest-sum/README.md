# Split Array Largest Sum

- **Difficulty:** Hard
- **Categories:** Array, Binary Search, Dynamic Programming, Greedy
- **Time Complexity:** O(N log S)
- **Space Complexity:** O(1)

---

Split array into m non-empty subarrays to minimize the largest subarray sum.

---

## Approach: Binary Search on Answer

Binary search on the answer (largest sum) in [max(nums), sum(nums)]. For each mid, greedily count the minimum splits needed. Minimize the valid range.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/split-array-largest-sum)
- [LeetCode](https://leetcode.com/problems/split-array-largest-sum/)
