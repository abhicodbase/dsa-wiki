# Longest Substring with At Most K Distinct Characters

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(K)

---

Find the length of the longest substring with at most k distinct characters.

---

## Approach: Sliding Window with Frequency Map

Same pattern as At Most Two Distinct but parameterized by k. When map size exceeds k, shrink from left. Track maximum window size.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/longest-substring-with-at-most-k-distinct-characters)
- [LeetCode](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
