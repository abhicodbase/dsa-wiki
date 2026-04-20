# Reverse Linked List

Given the head of a singly linked list, reverse the list and return the reversed list's head.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1) (iterative) / O(n) (recursive call stack)

---
### Approach
**Iterative**: Maintain three pointers — `prev`, `current`, and `next`. At each step, reverse the `next` pointer of `current` to point to `prev`, then advance all three pointers forward.

**Recursive**: Recursively reverse the rest of the list, then fix the pointers on the way back up the call stack.
