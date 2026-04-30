# Binary Subarrays With Sum

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Sliding Window, Prefix Sum

---

## Complexity Analysis

- **Time Complexity:** $O(N)$
  - We iterate through the array of length $N$ exactly once.
  - Insertions and lookups in the unordered hash map take $O(1)$ time on average.
- **Space Complexity:** $O(N)$
  - In the worst case, all prefix sums are distinct, meaning the hash map will store up to $N + 1$ unique keys.

---

Given a binary array and a goal, return the number of non-empty subarrays with sum equal to goal.

---

## Approach: Prefix Sum + Hash Map

Maintain a prefix sum frequency map. For each index, calculate the current prefix sum. Then, look up if `prefixSum - goal` exists in the map and add its frequency to the total count. This works because if `prefix[j] - prefix[i] == goal`, then the sum of elements between index `i+1` and `j` is exactly `goal`.

---

## Related Interview Questions
- [Subarray Sum Equals K](../subarray-sum-equals-k/README.md)
- [Continuous Subarray Sum](../continuous-subarray-sum/README.md)
- [Contiguous Array](../contiguous-array/README.md)
- [Subarrays with K Different Integers](../subarrays-with-k-different-integers/README.md)

---

## Learn More
- [NeetCode](https://neetcode.io/problems/binary-subarrays-with-sum)
- [LeetCode](https://leetcode.com/problems/binary-subarrays-with-sum/)
