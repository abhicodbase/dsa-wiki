# Maximum XOR of Two Numbers in an Array

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Bit Manipulation, Trie
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find the maximum XOR of any two numbers in the array.

---

## Approach: Bit Trie

Build a binary Trie from all numbers (MSB to LSB). For each number, greedily choose the opposite bit at each level to maximize XOR. Track maximum.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/maximum-xor-of-two-numbers-in-an-array)
- [LeetCode](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
