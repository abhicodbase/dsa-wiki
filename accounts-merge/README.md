# Accounts Merge

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, String, Depth-First Search, Breadth-First Search, Union Find
- **Time Complexity:** O(N·K·log(NK))
- **Space Complexity:** O(NK)

---

Merge accounts that share at least one common email. Return merged accounts with sorted emails.

---

## Approach: Union-Find on Emails

Map each email to an account index. Union all emails belonging to the same account. Group emails by their root representative, sort within groups, and format output.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/accounts-merge)
- [LeetCode](https://leetcode.com/problems/accounts-merge/)
