# Merge K Sorted Lists - Explanation

You are given an array of $k$ linked-lists `lists`, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.

## Approach 1: Min-Priority Queue (Heap)

### The Core Idea
We use a min-priority queue to keep track of the head of each list. We repeatedly extract the minimum element and add it to our merged list, then take the next element from the same list and put it back into the priority queue.

### Heap Visualization
```mermaid
graph TD
    PQ["Min-Priority Queue [Heads]"] --> Extract["Pop Minimum Node"]
    Extract --> Append["Add to Merged List"]
    Append --> Next["Push node->next if it exists"]
    Next --> PQ
```

### Complexity
- **Time Complexity:** $O(N \log K)$ where $N$ is total number of nodes and $K$ is number of lists.
- **Space Complexity:** $O(K)$ for the priority queue.

---

## Approach 2: Divide and Conquer

### The Core Idea
Merge lists in pairs using a merge strategy similar to Merge Sort.

### Merge Process Diagram
```mermaid
graph TD
    L1["List 1"] & L2["List 2"] --> M1["Merged List 1+2"]
    L3["List 3"] & L4["List 4"] --> M2["Merged List 3+4"]
    M1 & M2 --> Final["Final Merged List"]
```

## 3. Visual Concept
![Merge K Sorted Lists Concept](./concept.png)

---

## 4. Learn More (External Resources)
For a deeper analysis and video explanations, check out these excellent resources:
- [NeetCode's Video Explanation](https://neetcode.io/problems/merge-k-sorted-lists)
- [AlgoMonster Explanation](https://algo.monster/problems/merge_k_sorted_lists)
- [GeeksforGeeks Article](https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/)
