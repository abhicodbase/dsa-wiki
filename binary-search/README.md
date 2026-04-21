# Binary Search

- **Difficulty:** Easy
- **Categories:** Array, Binary Search
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

Given a sorted array and a target, return target's index or -1 if not found.

---

## Approach: Classic Binary Search

Maintain lo and hi pointers. Compute mid = lo + (hi-lo)/2. If nums[mid] == target return mid. If target > nums[mid], search right half; else left half.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/binary-search)
- [LeetCode](https://leetcode.com/problems/binary-search/)
