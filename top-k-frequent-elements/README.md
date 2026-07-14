# Top K Frequent Elements

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Divide and Conquer, Sorting, Heap, Bucket Sort, Quickselect

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Min-Heap** | $O(N \log K)$ | $O(N)$ | Simple heap tracking. Capping heap size at $K$ avoids sorting all elements. |
| **Bucket Sort** | $O(N)$ | $O(N)$ | Optimal approach. Groups elements by their exact frequency values into array indices. |

---

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in **any order**.

**Examples:**
```
Input:  nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input:  nums = [1], k = 1
Output: [1]
```

---

## Approach 1: Min-Heap of Size K

1. **Frequency Mapping**: Count occurrences of each integer using an `unordered_map<int, int>`.
2. **Size-Constrained Heap**:
   - Maintain a min-heap of size $K$ using `std::priority_queue` with `std::greater`.
   - Push each `{frequency, element}` pair into the heap.
   - If the size exceeds $K$, pop the top element (which is the least frequent element currently in the heap).
   - This ensures the heap only contains the $K$ most frequent elements.
3. **Extraction**: Collect elements from the heap into our result array.

---

## Approach 2: Bucket Sort (Optimal)

Since the maximum possible frequency of any element is $N$ (the length of the array), we can use a variation of Bucket Sort to solve this in linear time.

1. **Frequency Mapping**: Count frequencies using a hash map.
2. **Frequency Buckets**:
   - Create an array of buckets where the index represents the frequency (from $0$ to $N$).
   - Place elements into the bucket corresponding to their frequency.
3. **Linear Scan**: Scan the buckets from highest index ($N$) down to lowest ($0$) and append elements until we collect $K$ elements.

---

## Files

| File | Description |
| :--- | :--- |
| [`heap.cpp`](./heap.cpp) | C++ solution using a min-heap of size $K$ |
| [`bucket_sort.cpp`](./bucket_sort.cpp) | Optimal linear-time C++ solution using bucket sort |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/top-k-frequent-elements)
- [LeetCode](https://leetcode.com/problems/top-k-frequent-elements/)
