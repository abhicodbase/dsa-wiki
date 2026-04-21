# Remove Duplicates from Sorted List

- **Difficulty:** Easy
- **Categories:** Linked List
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given a sorted linked list, delete all duplicates so each element appears only once.

---

## Approach: Single Pass

Traverse the list. If current node's value equals next node's value, skip the next node (current.next = current.next.next). Otherwise advance current.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/remove-duplicates-from-sorted-list)
- [LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
