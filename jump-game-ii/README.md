# Jump Game II

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given array of jump lengths, return the minimum number of jumps to reach the last index.

---

## Approach: Greedy (BFS Level Tracking)

Track current reach and farthest reachable position. When index reaches current reach boundary, increment jumps and extend reach. Stop when last index is reached.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/jump-game-ii)
- [LeetCode](https://leetcode.com/problems/jump-game-ii/)
