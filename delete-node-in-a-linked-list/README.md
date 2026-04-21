# Delete Node in a Linked List

- **Difficulty:** Medium
- **Categories:** Linked List
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Delete a node (not tail) in a singly linked list given only access to that node.

---

## Approach: Copy Next Node's Value

Copy the value of next node into the current node, then set current.next = current.next.next. This effectively deletes the current node.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/delete-node-in-a-linked-list)
- [LeetCode](https://leetcode.com/problems/delete-node-in-a-linked-list/)
