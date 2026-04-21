# Contains Duplicate II

- **Difficulty:** Easy
- **Categories:** Array, Hash Table, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(min(N,K))

---

Given array nums and integer k, return true if there's i ≠ j with nums[i] == nums[j] and abs(i-j) ≤ k.

---

## Approach: Sliding Window Hash Set

Maintain a hash set of size k. For each element, check if it's in the set, then add it and remove nums[i-k] to maintain the window.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/contains-duplicate-ii)
- [LeetCode](https://leetcode.com/problems/contains-duplicate-ii/)
