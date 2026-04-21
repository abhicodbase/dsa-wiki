# Longest Repeating Character Replacement

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(26)

---

Given a string, you can replace at most k characters. Find the length of the longest substring containing the same letter after replacements.

---

## Approach: Sliding Window + Max Frequency

Maintain a window and a frequency map. The window is valid if windowLen - maxFreq ≤ k. Expand right always; shrink left when invalid. Track max window size.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/longest-repeating-character-replacement)
- [LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/)
