# Hand of Straights

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Greedy, Sorting
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Can you divide a hand of cards into groups of groupSize consecutive cards?

---

## Approach: Greedy with Sorted Map

Sort and use a frequency map. Start groups from the smallest card. For each group of size groupSize, decrement frequency of each consecutive card. Return false if any cannot be formed.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/hand-of-straights)
- [LeetCode](https://leetcode.com/problems/hand-of-straights/)
