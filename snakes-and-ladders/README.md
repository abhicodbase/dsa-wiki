# Snakes and Ladders

- **Difficulty:** Medium
- **Categories:** Array, Breadth-First Search, Matrix
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N²)

---

Find minimum number of moves to reach last cell in a snakes-and-ladders board.

---

## Approach: BFS on Board Positions

BFS from cell 1. For each cell, simulate 6 dice rolls (next 1-6 cells). Apply any snake/ladder at destination. Track visited cells. Return moves when last cell is reached.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/snakes-and-ladders)
- [LeetCode](https://leetcode.com/problems/snakes-and-ladders/)
