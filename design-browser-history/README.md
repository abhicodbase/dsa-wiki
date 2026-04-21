# Design Browser History

- **Difficulty:** Medium
- **Categories:** Array, Linked List, Stack, Design, Doubly-Linked List
- **Time Complexity:** O(1) visit, O(steps) back/fwd
- **Space Complexity:** O(N)

---

Design a browser history system with visit(url), back(steps), forward(steps).

---

## Approach: Array with Current Index

Use a list and a current index. Visit: append url and truncate forward history. Back: move index left by min(steps, current). Forward: move right by min(steps, remaining).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/design-browser-history)
- [LeetCode](https://leetcode.com/problems/design-browser-history/)
