# Asteroid Collision

- **Difficulty:** Medium
- **Categories:** Array, Stack, Simulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Asteroids move right (+) or left (-). When they collide, the smaller one explodes. Equal-size both explode. Find the final state.

---

## Approach: Stack Simulation

Push positive asteroids onto stack. For negative asteroids: while stack has positive top and it's smaller, pop (it explodes). If equal, pop and skip current. If stack is empty or top negative, push.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/asteroid-collision)
- [LeetCode](https://leetcode.com/problems/asteroid-collision/)
