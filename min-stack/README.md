# Min Stack

- **Difficulty:** Medium
- **Categories:** Stack, Design
- **Time Complexity:** O(1)
- **Space Complexity:** O(N)

---

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

---

## Approach: Auxiliary Min Stack

Maintain two stacks: main stack and min stack. On push, push min(val, minStack.top()) to min stack. On pop, pop from both. getMin() peeks min stack.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/min-stack)
- [LeetCode](https://leetcode.com/problems/min-stack/)
