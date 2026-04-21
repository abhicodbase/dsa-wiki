# Koko Eating Bananas

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(N log M)
- **Space Complexity:** O(1)

---

Koko has piles of bananas and h hours. Find minimum eating speed k (bananas/hour) to finish all piles within h hours.

---

## Approach: Binary Search on Answer

Search speed k in [1, max(piles)]. For each k, verify if sum(ceil(pile/k)) ≤ h. Binary search for the minimum valid k.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/koko-eating-bananas)
- [LeetCode](https://leetcode.com/problems/koko-eating-bananas/)
