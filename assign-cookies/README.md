# Assign Cookies

- **Difficulty:** Easy
- **Categories:** Array, Two Pointers, Greedy, Sorting
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(1)

---

Assign cookies to children. Each child has a greed factor; a cookie satisfies a child if cookie size >= greed. Maximize satisfied children.

---

## Approach: Sort + Two Pointers

Sort both greed and cookie arrays. Use two pointers: if Cookie[j] >= greed[i], satisfy this child (advance both pointers); else try next cookie (advance j only).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/assign-cookies)
- [LeetCode](https://leetcode.com/problems/assign-cookies/)
