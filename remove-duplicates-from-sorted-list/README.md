# Remove Duplicates from Sorted List

**LeetCode #83** · [LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) · [NeetCode](https://neetcode.io/problems/remove-duplicates-from-sorted-list)

- **Difficulty:** Easy
- **Categories:** Linked List
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

## Problem Statement

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

**Examples:**
```
Input:  head = [1,1,2]        →  Output: [1,2]
Input:  head = [1,1,2,3,3]    →  Output: [1,2,3]
```

---

## Intuition

Since the input linked list is already sorted, all elements with duplicate values are guaranteed to be adjacent to each other. This property allows us to solve the problem by checking adjacent nodes in a single traversal.

As we iterate through the list, if a node's value is equal to the next node's value, we can simply adjust the current node's `next` pointer to skip (and in languages like C++, delete) the next node. Otherwise, we advance the pointer to the next node.

---

## Approach: Single Pass

To solve this:
1. Initialize a pointer `current` at the `head` of the list.
2. While `current` and `current->next` are not null:
   - If `current->val` matches `current->next->val`:
     - Keep a temporary pointer to `current->next` (to free memory later).
     - Update `current->next` to point to `current->next->next` (bypassing the duplicate).
     - Delete the temporary pointer to avoid memory leaks.
   - Otherwise, advance `current` to `current->next`.
3. Return the original `head` pointer.

```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp; // Free memory
        } else {
            current = current->next;
        }
    }
    return head;
}
```

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time**  | O(N) | We traverse the linked list of length $N$ exactly once. |
| **Space** | O(1) | No extra memory is allocated. We only modify the existing linked list pointers in-place. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Empty list `head = nullptr` | `nullptr` |
| Single element list `head = [1]` | `[1]` |
| All duplicates `head = [1,1,1,1]` | `[1]` |
| No duplicates `head = [1,2,3]` | `[1,2,3]` |

---

## Files

| File | Description |
|---|---|
| [`single-pass.cpp`](./single-pass.cpp) | Main C++ solution using a single-pass iterative approach with full inline comments and test cases. |
| [`README.md`](./README.md) | Problem description, approach documentation, and complexity analysis. |

---

## Related Problems

- [Remove Duplicates from Sorted List II (LC #82)](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) — A variation where you must delete *all* nodes that have duplicate numbers, leaving only unique numbers.
- [Remove Element (LC #27)](https://leetcode.com/problems/remove-element/) — Modifying an array in-place to remove specific elements.
- [Delete Node in a Linked List (LC #237)](https://leetcode.com/problems/delete-node-in-a-linked-list/) — In-place deletion of a node when given access only to that node.
