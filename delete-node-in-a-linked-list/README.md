# Delete Node in a Linked List

**LeetCode #237** · [LeetCode](https://leetcode.com/problems/delete-node-in-a-linked-list/) · [NeetCode](https://neetcode.io/problems/delete-node-in-a-linked-list)

- **Difficulty:** Medium
- **Categories:** Linked List
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

## Problem Statement

There is a single-linked list `head` and we want to delete a node `node` in it.

You are given the node to be deleted `node`. You will **not** be given access to the `head` of the list.

All the values of the linked list are unique, and it is guaranteed that the given node `node` is **not a tail node** in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
- The value of the given node should not exist in the linked list.
- The number of nodes in the linked list should decrease by one.
- All the values before `node` should be in the same order.
- All the values after `node` should be in the same order.

**Examples:**
```
Input:  head = [4,5,1,9], node = 5  →  Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9.

Input:  head = [4,5,1,9], node = 1  →  Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9.
```

---

## Intuition

Usually, deleting a node from a singly linked list requires finding the previous node (`prev`) and setting `prev->next = node->next`. However, here we are given direct access **only** to the node to be deleted, without any access to `head` or the predecessor node.

Since we cannot change `prev->next`, we can instead copy the value of `node->next` into `node->val`, and then bypass `node->next` by updating `node->next = node->next->next`.

Effectively, we overwrite the current node's data with its successor's data and splice out the successor node instead. To a reader of the linked list, the target node appears deleted in $O(1)$ time.

---

## Approach: Value Copying & Pointer Bypass

To implement this:
1. Copy the value of the next node into the current node: `node->val = node->next->val`.
2. Save a reference to `node->next` for memory deallocation.
3. Update the current node's `next` pointer to skip the next node: `node->next = node->next->next`.
4. (In C++) `delete` the unlinked next node to avoid memory leaks.

```cpp
void deleteNode(ListNode* node) {
    // Store pointer to next node for memory cleanup
    ListNode* temp = node->next;
    
    // Overwrite current node's value with next node's value
    node->val = temp->val;
    
    // Bypass next node
    node->next = temp->next;
    
    // Free memory of bypassed node
    delete temp;
}
```

---

## Complexity

| Operation | Time Complexity | Space Complexity | Reason |
|---|---|---|---|
| **`deleteNode`** | O(1) | O(1) | Performs a constant number of operations: 1 value copy, 1 pointer assignment, and 1 memory deallocation. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Node is the second node in list | Successfully updated value and bypassed; head remains unchanged. |
| Node is the second-to-last node | Successfully updated value to match last node and set `next = nullptr`. |
| Node is the tail node | Not applicable per problem constraints (guaranteed `node` is not the tail). |
| Node is the first node (`head`) | Works identically as long as pointer to `head` is passed as `node`. |

---

## Files

| File | Description |
|---|---|
| [`value-copy.cpp`](./value-copy.cpp) | Main C++ solution using value copying and pointer bypass with full inline comments and test driver. |
| [`README.md`](./README.md) | Problem description, approach documentation, complexity analysis, and edge cases. |

---

## Related Problems

- [Remove Linked List Elements (LC #203)](https://leetcode.com/problems/remove-linked-list-elements/) — Standard linked list node removal given the head pointer.
- [Remove Nth Node From End of List (LC #19) ](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) — Two-pointer approach to delete a target node relative to the end.
- [Remove Duplicates from Sorted List (LC #83)](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) — In-place pointer updating to skip duplicate nodes.
