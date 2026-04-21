# Super Ugly Number

- **Difficulty:** Medium
- **Categories:** Array, Math, Dynamic Programming
- **Time Complexity:** O(N×K)
- **Space Complexity:** O(N+K)

---

An ugly number has only primes from a given list as factors. Return the n-th super ugly number.

---

## Approach: DP with K Pointers

Maintain an array dp and pointers for each prime. Next ugly = min of prime[i] * dp[ptr[i]]. Advance all pointers that produced the minimum to avoid duplicates.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/super-ugly-number)
- [LeetCode](https://leetcode.com/problems/super-ugly-number/)
