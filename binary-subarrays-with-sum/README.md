# Binary Subarrays With Sum

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Sliding Window, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given a binary array and a goal, return the number of non-empty subarrays with sum equal to goal.

---

## Approach: Prefix Sum + Hash Map

Maintain prefix sum frequency map. For each index, add freq[prefixSum - goal] to count. Same pattern as Subarray Sum Equals K.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/binary-subarrays-with-sum)
- [LeetCode](https://leetcode.com/problems/binary-subarrays-with-sum/)
