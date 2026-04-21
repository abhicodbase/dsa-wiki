# Happy Number

- **Difficulty:** Easy
- **Categories:** Hash Table, Math, Two Pointers
- **Time Complexity:** O(log N)
- **Space Complexity:** O(log N)

---

A happy number reaches 1 when repeatedly replacing it with sum of squares of digits. Determine if n is happy.

---

## Approach: Floyd's Cycle Detection on Sum-of-Squares

Use slow/fast pointers on the sequence. If fast reaches 1, it is happy. If slow==fast (cycle), it is not happy.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/happy-number)
- [LeetCode](https://leetcode.com/problems/happy-number/)
