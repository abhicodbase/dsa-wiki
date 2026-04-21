# Lemonade Change

- **Difficulty:** Easy
- **Categories:** Array, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

$5 lemonades. Customers pay $5, $10, or $20. Return true if you can give correct change to every customer.

---

## Approach: Greedy (Track Bills)

Track count of $5 and $10 bills. For $10: use one $5. For $20: prefer $10+$5 over three $5s (to preserve $5s). Return false if change impossible.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/lemonade-change)
- [LeetCode](https://leetcode.com/problems/lemonade-change/)
