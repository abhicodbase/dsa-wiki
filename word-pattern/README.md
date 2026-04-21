# Word Pattern

- **Difficulty:** Easy
- **Categories:** Hash Table, String
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given a pattern string and a string s, determine if s follows the same pattern (bijection between pattern chars and words).

---

## Approach: Bidirectional Hash Map

Split s into words. Map each pattern character to its word and each word to its character. Verify consistency bidirectionally at each step.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/word-pattern)
- [LeetCode](https://leetcode.com/problems/word-pattern/)
