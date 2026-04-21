# Burst Balloons

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming, Divide and Conquer
- **Time Complexity:** O(N³)
- **Space Complexity:** O(N²)

---

Given balloons with values, burst them all collecting coins = nums[left]*nums[i]*nums[right]. Maximize total coins.

---

## Approach: Interval DP (Last to Burst)

Think of which balloon is burst LAST in each interval. dp[l][r] = max coins from interval [l,r]. dp[l][r] = max over k: nums[l-1]*nums[k]*nums[r+1] + dp[l][k-1] + dp[k+1][r].

---

## Learn More
- [NeetCode](https://neetcode.io/problems/burst-balloons)
- [LeetCode](https://leetcode.com/problems/burst-balloons/)
