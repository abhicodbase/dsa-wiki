# Flood Fill

- **Difficulty:** Easy
- **Categories:** Array, Depth-First Search, Breadth-First Search, Matrix
- **Time Complexity:** O(MxN)
- **Space Complexity:** O(MxN)

---

Perform a flood fill starting from pixel (sr, sc), changing its color and all 4-directionally connected same-color pixels to newColor.

---

## Approach: DFS / BFS from Source

Record original color. DFS from (sr, sc): if current cell matches original color, paint it newColor and recurse on 4 neighbors. Handle edge case where original == newColor.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/flood-fill)
- [LeetCode](https://leetcode.com/problems/flood-fill/)
