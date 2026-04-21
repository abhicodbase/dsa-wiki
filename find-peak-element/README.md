# Find Peak Element

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

A peak element is strictly greater than its neighbors. Return the index of any peak. There may be multiple peaks.

---

## Approach: Binary Search

If nums[mid] < nums[mid+1], there's a peak in the right half. Otherwise the peak is in the left half or at mid. Binary search converges to a peak.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-peak-element)
- [LeetCode](https://leetcode.com/problems/find-peak-element/)
