# Reorder List

Given the head of a singly linked list `L0 → L1 → … → Ln-1 → Ln`, reorder it to: `L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …`. Do this in-place without altering node values.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Three steps:
1. **Find the middle** of the list using the slow/fast pointer technique.
2. **Reverse the second half** of the list in place.
3. **Merge** the two halves by alternating nodes from each half.
