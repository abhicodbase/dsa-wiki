# Delete and Earn

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Dynamic Programming
- **Time Complexity:** O(N + max(nums))
- **Space Complexity:** O(max(nums))

---

Pick a number nums[i]: earn nums[i] points but delete all equal to nums[i]-1 and nums[i]+1. Maximize points.

---

## Approach: Transform to House Robber

Create points array where points[v] = v × count(v). Adjacent values conflict → standard House Robber DP on the points array.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/delete-and-earn)
- [LeetCode](https://leetcode.com/problems/delete-and-earn/)
