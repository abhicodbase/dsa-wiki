# As Far from Land as Possible

- **Difficulty:** Medium
- **Categories:** Array, Breadth-First Search, Matrix, Dynamic Programming
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N^2)

---

Find the water cell that maximizes its Manhattan distance to any land cell. Return -1 if no water or land exists.

---

## Approach: Multi-Source BFS from All Land

BFS from all land cells simultaneously. The last cell reached by BFS is the water cell farthest from all land. Return its distance.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/as-far-from-land-as-possible)
- [LeetCode](https://leetcode.com/problems/as-far-from-land-as-possible/)
