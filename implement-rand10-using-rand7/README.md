# Implement Rand10 Using Rand7

- **Difficulty:** Medium
- **Categories:** Math, Rejection Sampling, Randomized, Probability and Statistics
- **Time Complexity:** O(1) avg
- **Space Complexity:** O(1)

---

Implement rand10() using rand7(). Each result should be uniformly distributed in [1, 10].

---

## Approach: Rejection Sampling with 2D Mapping

Generate random number in [1, 49] using (rand7()-1)*7 + rand7(). Reject [41, 49] (unequal distribution). Map [1, 40] to [1, 10] using modulo.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/implement-rand10-using-rand7)
- [LeetCode](https://leetcode.com/problems/implement-rand10-using-rand7/)
