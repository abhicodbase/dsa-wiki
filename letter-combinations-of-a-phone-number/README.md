# Letter Combinations of a Phone Number

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Backtracking
- **Time Complexity:** O(4^N × N)
- **Space Complexity:** O(N)

---

Given a string of digits 2-9, return all possible letter combinations the digits could represent (phone keypad mapping).

---

## Approach: DFS Backtracking

Map each digit to its letters. DFS: at each level choose one letter for current digit and recurse. When path length equals digits length, add to result.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/letter-combinations-of-a-phone-number)
- [LeetCode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
