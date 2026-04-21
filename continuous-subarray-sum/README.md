# Continuous Subarray Sum

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Math, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Return true if there is a subarray of length >= 2 whose sum is a multiple of k.

---

## Approach: Prefix Sum Mod K

If prefix[j] % k == prefix[i] % k, then sum(i..j) is divisible by k. Store first-seen index of each remainder. Check if j - stored_index >= 2.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/continuous-subarray-sum)
- [LeetCode](https://leetcode.com/problems/continuous-subarray-sum/)
