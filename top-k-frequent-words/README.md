# Top K Frequent Words

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Sorting, Heap, Bucket Sort

---

## Complexity Analysis

- **Time Complexity:** $O(N \log K)$ where $N$ is the number of words.
  - Counting frequencies using a hash map takes $O(N)$ time.
  - Iterating over unique words and pushing/popping from a priority queue of maximum size $K$ takes $O(U \log K)$ where $U$ is the number of unique words ($U \le N$).
- **Space Complexity:** $O(N)$
  - Storing word frequencies in the hash map takes $O(U)$ space, where $U$ is the number of unique words.
  - The min-heap takes $O(K)$ space.

---

Given an array of strings `words` and an integer `k`, return the `k` most frequent strings.

Return the answer **sorted** by **frequency** from highest to lowest. Sort the words with the same frequency by their **lexicographical order**.

**Examples:**
```
Input:  words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words. "i" comes before "love" due to lower alphabetical order.
```

---

## Approach: Min-Heap of Size K

The most common way to solve "Top K" problems is using a Heap/Priority Queue.

1. **Frequency Mapping**: Count occurrences of each word using an `unordered_map<string, int>`.
2. **Min-Heap Optimization**:
   - Instead of sorting all elements ($O(N \log N)$) or pushing all unique elements to a heap of size $N$ ($O(N \log N)$), we maintain a min-heap capped at size $K$. This keeps pushes/pops at $O(\log K)$ cost.
   - **Custom Comparator Criteria**:
     - **Frequencies**: We want a min-heap on frequency. The word with the *smallest* frequency should sit at the top of the heap, so it gets popped off first when the heap size exceeds $K$.
     - **Lexicographical Ties**: If two words have the same frequency, we want the lexicographically *larger* string (e.g. `"love"` over `"i"`) at the top of the heap. This way, the lexicographically larger word gets popped off first when size exceeds $K$, leaving the lexicographically smaller word inside the heap.
3. **Reversal**: Popping elements from a min-heap yields elements in ascending order (least frequent to most frequent). Reversing the final extracted list gives the correct descending order.

---

## Files

| File | Description |
| :--- | :--- |
| [`min_heap.cpp`](./min_heap.cpp) | C++ solution using `unordered_map` and a size-constrained `priority_queue` with a custom comparator |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/top-k-frequent-words)
- [LeetCode](https://leetcode.com/problems/top-k-frequent-words/)
