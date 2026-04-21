# Design Underground System

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Design
- **Time Complexity:** O(1)
- **Space Complexity:** O(N)

---

Track passengers checking in/out of stations. Return average travel time between two stations.

---

## Approach: Two Hash Maps

Map1: id → (station, time) for checked-in passengers. Map2: (start, end) → (totalTime, tripCount). CheckIn: update Map1. CheckOut: compute time, update Map2. GetAverage: Map2 lookup.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/design-underground-system)
- [LeetCode](https://leetcode.com/problems/design-underground-system/)
