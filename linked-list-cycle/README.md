# Linked List Cycle

Given the head of a linked list, determine if the linked list has a cycle in it.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Use Floyd's Cycle Detection Algorithm (Tortoise and Hare). Use two pointers — `slow` (moves 1 step) and `fast` (moves 2 steps). If there is a cycle, `fast` will eventually lap `slow` and they will meet. If `fast` reaches `nullptr`, there is no cycle.
