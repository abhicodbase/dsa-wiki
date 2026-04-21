# Climbing Stairs

- **Difficulty:** Easy
- **Categories:** Math, Dynamic Programming, Memoization
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

You can climb 1 or 2 steps at a time. How many distinct ways can you climb to the top (n steps)?

---

## Approach: Fibonacci DP

f(n) = f(n-1) + f(n-2). Base cases: f(1)=1, f(2)=2. Use two variables instead of full array for O(1) space.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/climbing-stairs)
- [LeetCode](https://leetcode.com/problems/climbing-stairs/)
