# Guess Number Higher or Lower

- **Difficulty:** Easy
- **Categories:** Binary Search, Interactive
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

You are guessing a number between 1 and n. The API guess(num) returns -1 (too high), 1 (too low), or 0 (correct). Find the number.

---

## Approach: Binary Search on Search Space

Apply binary search on [1, n]. Call guess(mid): if 0 return mid, if 1 search right half, if -1 search left half.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/guess-number-higher-or-lower)
- [LeetCode](https://leetcode.com/problems/guess-number-higher-or-lower/)
