# Basic Calculator II

- **Difficulty:** Medium
- **Categories:** Math, String, Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Evaluate a string expression with +, -, *, / operators (no parentheses). Integer division truncates toward zero.

---

## Approach: Stack with Operator Precedence

Process digits to form numbers. For +/-: push ±num to stack. For *//: pop stack top, compute, push result. Sum stack at the end.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/basic-calculator-ii)
- [LeetCode](https://leetcode.com/problems/basic-calculator-ii/)
