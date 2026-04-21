# Majority Element

- **Difficulty:** Easy
- **Categories:** Array, Hash Table, Sorting, Boyer-Moore
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an array of size n, return the majority element — the element that appears more than n/2 times. It always exists.

---

## Approach: Boyer-Moore Voting Algorithm

Maintain a candidate and a count. For each element: if count is 0, set candidate = element; if element equals candidate, increment count; else decrement count. The final candidate is the majority element.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/majority-element)
- [LeetCode](https://leetcode.com/problems/majority-element/)
