# Divisor Game

- **Difficulty:** Easy
- **Categories:** Math, Dynamic Programming, Brainteaser

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Mathematical Observation** | $O(1)$ | $O(1)$ | Optimal approach. Alice wins if and only if $N$ is even. |
| **Dynamic Programming** | $O(N \sqrt{N})$ | $O(N)$ | Iteratively computes winning/losing states for numbers up to $N$. |

---

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number `n` on the chalkboard. On each player's turn, that player makes a move consisting of:
1. Choosing any `x` with `0 < x < n` and `n % x == 0`.
2. Replacing the number `n` on the chalkboard with `n - x`.

Also, if a player cannot make a move, they lose the game.

Return `true` if and only if Alice wins the game, assuming both players play optimally.

---

## Approach 1: Mathematical Observation (Optimal)

Alice wins if and only if $N$ is even.

### Proof by Induction
1. **Base Cases**:
   - $N = 1$: The player whose turn it is cannot make any move ($0 < x < 1$ has no integer solutions). Thus, the active player loses (returns `false`).
   - $N = 2$: Active player chooses $x = 1$, leaving the opponent with $N = 1$. Opponent loses. Thus, active player wins (returns `true`).
2. **Induction Hypothesis**:
   - Assume that for all numbers $< K$, an even number is a winning state and an odd number is a losing state.
3. **Inductive Step for $K$**:
   - **If $K$ is even**: The active player can always choose $x = 1$. The opponent is left with $K - 1$, which is odd. Since odd is a losing state by the hypothesis, the active player wins.
   - **If $K$ is odd**: All divisors of an odd number are odd. Subtracting an odd divisor $x$ from an odd number $K$ leaves an even number $K - x$. The opponent is left with an even number. Since even is a winning state by the hypothesis, the opponent wins, meaning the active player loses.

Thus, even numbers are always winning states, and odd numbers are always losing states.

---

## Approach 2: Dynamic Programming

We can model the game recursively using a boolean DP array:
1. Let `dp[i]` be `true` if the current player wins starting with number `i`.
2. For each number `i` from `2` to `N`, find all of its divisors `x`.
3. If there exists some divisor `x` such that `dp[i - x] == false` (the opponent is forced into a losing state), then `dp[i] = true`.
4. If no such move exists, the active player loses, so `dp[i] = false`.

---

## Files

| File | Description |
| :--- | :--- |
| [`divisor_game.cpp`](./divisor_game.cpp) | Optimal $O(1)$ Math observation solution |
| [`dp.cpp`](./dp.cpp) | Dynamic Programming solution with $O(N \sqrt{N})$ time complexity |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/divisor-game)
- [LeetCode](https://leetcode.com/problems/divisor-game/)
