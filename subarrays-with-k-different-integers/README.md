# Subarrays with K Different Integers

- **Difficulty:** Hard
- **Categories:** Array, Hash Table, Sliding Window, Counting
- **Time Complexity:** O(N)
- **Space Complexity:** O(K)

---

Count subarrays with exactly K different integers.

---

## Approach: Exactly K = At Most K - At Most K-1

Compute atMostK(nums, k) - atMostK(nums, k-1). atMostK uses sliding window with a frequency map, expanding right and shrinking left when distinct count exceeds k.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/subarrays-with-k-different-integers)
- [LeetCode](https://leetcode.com/problems/subarrays-with-k-different-integers/)
