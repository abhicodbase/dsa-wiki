# Basic Calculator

- **Difficulty:** Hard
- **Categories:** Math, String, Stack, Recursion
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Implement a basic calculator to evaluate a string expression with +, -, (, ) and spaces.

---

## Approach: Stack for Sign

Maintain result, sign (+1/-1), and stack. On '(': push result and sign onto stack, reset. On ')': result = stack.pop() * result + stack.pop(). Accumulate digits.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/basic-calculator)
- [LeetCode](https://leetcode.com/problems/basic-calculator/)
