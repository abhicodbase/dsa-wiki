# Divisor Game

- **Difficulty:** Easy
- **Categories:** Math, Dynamic Programming, Brainteaser
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Alice and Bob play: pick a divisor of n, subtract it. Lose when you cannot move. Alice goes first. Does Alice win?

---

## Approach: Math Observation

Alice wins if and only if n is even. If n is even, Alice subtracts 1 leaving odd for Bob. Inductive argument shows even always wins for the first player.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/divisor-game)
- [LeetCode](https://leetcode.com/problems/divisor-game/)
