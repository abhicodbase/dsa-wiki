# Evaluate Reverse Polish Notation

- **Difficulty:** Medium
- **Categories:** Array, Math, Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Evaluate the value of an expression in Reverse Polish Notation (postfix).

---

## Approach: Stack-Based Evaluation

Push numbers to stack. For operators, pop two operands, apply the operator, and push the result. Return the final value on the stack.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/evaluate-reverse-polish-notation)
- [LeetCode](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
