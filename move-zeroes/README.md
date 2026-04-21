# Move Zeroes

- **Difficulty:** Easy
- **Categories:** Array, Two Pointers
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an array `nums`, move all 0s to the end while maintaining the relative order of non-zero elements. Do it in-place.

---

## Approach: Two Pointers (Snowball)

Keep a slow pointer tracking the next position for a non-zero element. Iterate with a fast pointer; when a non-zero is found, swap it to the slow pointer position and advance both.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/move-zeroes)
- [LeetCode](https://leetcode.com/problems/move-zeroes/)
