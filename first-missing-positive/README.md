# First Missing Positive

- **Difficulty:** Hard
- **Categories:** Array, Hash Table
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an unsorted integer array `nums`, return the smallest missing positive integer. Must run in O(N) time and O(1) extra space.

---

## Approach: Index as Hash (Cyclic Sort)

Place each number x in index x-1 if 1 ≤ x ≤ n. Then scan: the first index i where nums[i] ≠ i+1 gives the answer i+1.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/first-missing-positive)
- [LeetCode](https://leetcode.com/problems/first-missing-positive/)
