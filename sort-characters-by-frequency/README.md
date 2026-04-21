# Sort Characters By Frequency

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sorting, Bucket Sort, Heap, Counting
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Sort characters in a string in decreasing order of frequency.

---

## Approach: Frequency Map + Bucket Sort

Count frequencies. Create buckets 0..n where bucket[i] contains characters with frequency i. Traverse buckets from high to low, appending each char frequency times.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/sort-characters-by-frequency)
- [LeetCode](https://leetcode.com/problems/sort-characters-by-frequency/)
