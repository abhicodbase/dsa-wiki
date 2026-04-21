# Dungeon Game

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

A knight must save a princess. Find the minimum initial health needed to reach the princess (bottom-right), avoiding dying (health ≤ 0) at any point.

---

## Approach: Reverse DP (Right-to-Left, Bottom-to-Top)

Fill dp from bottom-right to top-left. dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]). Ensures minimum health needed at each cell.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/dungeon-game)
- [LeetCode](https://leetcode.com/problems/dungeon-game/)
