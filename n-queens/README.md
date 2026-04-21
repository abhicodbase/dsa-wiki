# N-Queens

- **Difficulty:** Hard
- **Categories:** Array, Backtracking
- **Time Complexity:** O(N!)
- **Space Complexity:** O(N)

---

Place n queens on an n×n chessboard so no two queens attack each other. Return all distinct solutions.

---

## Approach: Backtracking with Column + Diagonal Sets

Track used columns, diagonals (row-col), and anti-diagonals (row+col) in sets. Place one queen per row, try all columns. Backtrack if conflict detected.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/n-queens)
- [LeetCode](https://leetcode.com/problems/n-queens/)
