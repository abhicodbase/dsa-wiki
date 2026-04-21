# Insert Delete GetRandom O(1)

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Math, Design, Randomized
- **Time Complexity:** O(1)
- **Space Complexity:** O(N)

---

Design a data structure with O(1) insert, delete, and getRandom (returns uniformly random element).

---

## Approach: HashMap + Array

Array stores elements. HashMap stores element→array index. Insert: append to array, store index. Remove: swap with last element, update map, pop last. GetRandom: return random array element.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/insert-delete-getrandom-o1)
- [LeetCode](https://leetcode.com/problems/insert-delete-getrandom-o1/)
