# Gas Station

There are `n` gas stations in a circle. Given `gas[i]` (fuel at station i) and `cost[i]` (fuel to travel to next station), find the starting station index from which you can complete the circuit, or return `-1` if impossible.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
If total gas < total cost, no solution exists. Otherwise, a valid solution always exists. Greedily find the start: iterate through stations tracking `tank`. When `tank` goes negative, reset it to 0 and set the next station as the candidate start. The candidate at the end of the pass is the answer.
