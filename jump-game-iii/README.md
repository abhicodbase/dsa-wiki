# Jump Game III

- **Difficulty:** Medium
- **Categories:** Array, Depth-First Search, Breadth-First Search
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Starting at index start, can you reach any index with value 0? From index i you can jump to i+arr[i] or i-arr[i].

---

## Approach: BFS / DFS

BFS/DFS from start. At each index i, try jumping to i+arr[i] and i-arr[i] if in bounds and not visited. Return true if a 0-value index is reached.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/jump-game-iii)
- [LeetCode](https://leetcode.com/problems/jump-game-iii/)
