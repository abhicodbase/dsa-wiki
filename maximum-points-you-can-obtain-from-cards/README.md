# Maximum Points You Can Obtain from Cards

- **Difficulty:** Medium
- **Categories:** Array, Sliding Window, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

You can take exactly k cards from either the beginning or end of a row of cards. Maximize total points.

---

## Approach: Sliding Window (Complement)

Instead of choosing k cards from both ends, find the minimum-sum subarray of length n-k in the middle. Total max = totalSum - minMiddleSum.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/maximum-points-you-can-obtain-from-cards)
- [LeetCode](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
