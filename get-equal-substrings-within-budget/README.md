# Get Equal Substrings Within Budget

- **Difficulty:** Medium
- **Categories:** String, Binary Search, Sliding Window, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

You can change characters in string s to match string t. Each char change costs |s[i]-t[i]|. Find max length substring you can equalize within budget maxCost.

---

## Approach: Sliding Window

Create cost array = |s[i]-t[i]|. Sliding window maintaining sum <= maxCost. Expand right, shrink left when sum exceeds budget. Track max window size.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/get-equal-substrings-within-budget)
- [LeetCode](https://leetcode.com/problems/get-equal-substrings-within-budget/)
