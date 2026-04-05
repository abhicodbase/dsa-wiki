# Valid Parentheses

Given a string `s` containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

---
### Approach
Use a stack to keep track of opening brackets. For each closing bracket, check if it matches the top of the stack.
