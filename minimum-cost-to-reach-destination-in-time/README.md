# Minimum Cost to Reach Destination in Time

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming, Graph
- **Time Complexity:** O(NxT)
- **Space Complexity:** O(NxT)

---

Given a graph with edges having time costs and nodes having fees, find minimum total fee to reach destination within maxTime.

---

## Approach: DP: dp[time][node] = min fees

dp[t][v] = minimum cost to reach v in exactly t time. Transition: for each edge (u,v,time): dp[t][v] = min(dp[t][v], dp[t-time][u] + fees[v]).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-cost-to-reach-destination-in-time)
- [LeetCode](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/)
