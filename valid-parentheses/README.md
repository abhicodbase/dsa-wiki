# Valid Parentheses

## Problem Description
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## Approach
A **stack** is perfect for this problem. We can iterate through the string and do the following:
1. If the current character is an opening bracket (`(`, `{`, `[`), push it onto the stack.
2. If it's a closing bracket (`)`, `}`, `]`), check if the stack is not empty and its top element matches the current closing bracket.
   - If it matches, pop the opening bracket from the stack.
   - If it doesn't match or the stack is empty, then the brackets are mismatched (invalid string).
3. At the end of the iteration, if the stack is empty, the string is valid (all opening brackets had matching closing brackets).

## Complexity
- **Time Complexity:** $O(N)$, where $N$ is the length of the string. We process each character in the string exactly once.
- **Space Complexity:** $O(N)$ in the worst-case scenario where we might push all characters onto the stack.
