# Candy

- **Difficulty:** Hard
- **Categories:** Array, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Give minimum candies to n children where each child with higher rating than neighbor gets more candies. Each child gets at least 1.

---

## Approach: Two-Pass Greedy

Left-to-right pass: give one more candy than left neighbor if rating is higher. Right-to-left pass: ensure right neighbor constraint. Sum all candy counts.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/candy)
- [LeetCode](https://leetcode.com/problems/candy/)
