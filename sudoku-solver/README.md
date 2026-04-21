# Sudoku Solver

- **Difficulty:** Hard
- **Categories:** Array, Backtracking, Matrix
- **Time Complexity:** O(9^M)
- **Space Complexity:** O(1)

---

Solve a Sudoku puzzle by filling empty cells (marked '.') with 1-9 following standard rules.

---

## Approach: Backtracking with Constraint Sets

Track used numbers for each row, column, and 3×3 box (using sets or bitmasks). For each empty cell, try 1-9, recurse. Backtrack if a dead end is reached.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/sudoku-solver)
- [LeetCode](https://leetcode.com/problems/sudoku-solver/)
