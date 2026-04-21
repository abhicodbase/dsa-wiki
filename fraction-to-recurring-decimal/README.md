# Fraction to Recurring Decimal

- **Difficulty:** Medium
- **Categories:** Hash Table, Math, String
- **Time Complexity:** O(D)
- **Space Complexity:** O(D)

---

Given numerator and denominator, return the fraction as a string. Repeating parts should be enclosed in parentheses.

---

## Approach: Long Division + Remainder Tracking

Simulate long division. Track position of each remainder in a map. When a remainder repeats, insert parentheses around the repeating portion.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/fraction-to-recurring-decimal)
- [LeetCode](https://leetcode.com/problems/fraction-to-recurring-decimal/)
