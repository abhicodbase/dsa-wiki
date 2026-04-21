# Pow(x, n)

- **Difficulty:** Medium
- **Categories:** Math, Recursion
- **Time Complexity:** O(log N)
- **Space Complexity:** O(log N)

---

Implement pow(x, n) which calculates x raised to the power n.

---

## Approach: Fast Exponentiation (Binary)

If n is even: x^n = (x²)^(n/2). If odd: x^n = x × (x²)^((n-1)/2). Handle n < 0 by computing (1/x)^(-n). O(log n) recursive calls.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/pow-x-n)
- [LeetCode](https://leetcode.com/problems/pow-x-n/)
