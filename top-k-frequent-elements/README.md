# Top K Frequent Elements

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements in any order.

### Complexity
- **Time Complexity**: O(n log k) using a heap; O(n) using bucket sort
- **Space Complexity**: O(n)

---
### Approach
**Heap**: Count frequencies with a hash map, then use a min-heap of size `k` to track the top-k elements. Final heap contents are the answer.

**Bucket Sort (Optimal)**: After counting frequencies, create buckets indexed by frequency (size n+1). Place each number in the bucket matching its frequency. Scan buckets from highest to lowest to collect the top k.
