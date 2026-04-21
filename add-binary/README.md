# Add Binary

- **Difficulty:** Easy
- **Categories:** Math, String, Bit Manipulation, Simulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given two binary strings a and b, return their sum as a binary string.

---

## Approach: Bit-by-Bit Addition from Right

Process digits from right to left with a carry variable. Add corresponding digits + carry, compute bit (sum%2) and update carry (sum/2). Prepend each bit to result.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/add-binary)
- [LeetCode](https://leetcode.com/problems/add-binary/)
