# Max Points on a Line

- **Difficulty:** Hard
- **Categories:** Array, Hash Table, Math, Geometry
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N)

---

Given an array of points, find the maximum number of points that lie on the same straight line.

---

## Approach: Slope Hashing per Point

For each point, compute slope to all other points as a reduced fraction. Use a hash map to count max same-slope count. Add 1 for the pivot point itself.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/max-points-on-a-line)
- [LeetCode](https://leetcode.com/problems/max-points-on-a-line/)
