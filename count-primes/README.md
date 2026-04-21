# Count Primes

- **Difficulty:** Medium
- **Categories:** Array, Math, Enumeration, Number Theory
- **Time Complexity:** O(N log log N)
- **Space Complexity:** O(N)

---

Count the number of prime numbers less than n.

---

## Approach: Sieve of Eratosthenes

Initialize boolean array of size n (all true). For each prime p from 2 to sqrt(n), mark all multiples of p as composite. Count remaining true values.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/count-primes)
- [LeetCode](https://leetcode.com/problems/count-primes/)
