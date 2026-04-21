# The Number of Weak Characters in the Game

- **Difficulty:** Medium
- **Categories:** Array, Stack, Greedy, Sorting, Monotonic Stack
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(1)

---

Count characters where both attack and defense are strictly less than another character's.

---

## Approach: Sort by Attack Desc, Defense Asc (Tie-breaking)

Sort by attack descending; for equal attack, sort by defense ascending. Iterate tracking max defense seen so far. If character's defense is less than max, it's weak.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/the-number-of-weak-characters-in-the-game)
- [LeetCode](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)
