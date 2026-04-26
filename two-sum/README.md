# Two Sum

- **Difficulty:** Easy
- **Categories:** Array, Hash Table

---

## Complexity Analysis

- **Time Complexity:** $O(N)$
  - We traverse the list of $N$ elements only once.
  - Each look-up in the hash map takes $O(1)$ time on average.
- **Space Complexity:** $O(N)$
  - The hash map stores at most $N$ elements (one for each number in the array).

---

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

---

## Approach: Hash Map (One Pass)

Use a hash map to store the value and its index. For each number, check if the complement (`target - num`) already exists in the map. If it does, we have found our solution. Otherwise, add the current number and its index to the map.

---

## Related Interview Questions
- [3Sum](../3sum/README.md)
- [4Sum](../4sum/README.md)
- [Two Sum II - Input Array Is Sorted](../two-sum-ii-input-array-is-sorted/README.md)
- [Subarray Sum Equals K](../subarray-sum-equals-k/README.md)

---

## Learn More
- [NeetCode](https://neetcode.io/problems/two-sum)
- [LeetCode](https://leetcode.com/problems/two-sum/)
