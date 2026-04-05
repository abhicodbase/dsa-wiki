# Median of Two Sorted Arrays - Explanation

The goal is to find the median of two sorted arrays $A$ and $B$ of size $n$ and $m$ respectively.

## Approach: Binary Search on Partition

### The Core Idea
We want to partition both arrays into two halves (Left and Right) such that:
1. The total number of elements in the combined Left half is equal to (or one more than) the total number of elements in the combined Right half.
2. Every element in the Left half is less than or equal to every element in the Right half.

### Partitioning Diagram
```mermaid
graph LR
    subgraph Array1
        A1["A[0...i-1]"] -- "L1" --> Partition1["|"] -- "R1" --> A2["A[i...n-1]"]
    end
    subgraph Array2
        B1["B[0...j-1]"] -- "L2" --> Partition2["|"] -- "R2" --> B2["B[j...m-1]"]
    end
    Partition1 --- Partition2
```

We need to find $i$ such that:
- $max(A[i-1], B[j-1]) \leq min(A[i], B[j])$

### Why Binary Search?
Since the arrays are sorted, we can binary search for the correct partition index $i$ in the smaller array. This gives us a very efficient logarithmic time complexity.

## 3. Visual Concept
![Median of Two Sorted Arrays Concept](./concept.png)

---

## 4. Learn More (External Resources)
For a deeper analysis and video explanations, check out these excellent resources:
- [NeetCode's Video Explanation](https://neetcode.io/problems/median-of-two-sorted-arrays)
- [TakeUForward (Striver's) Article](https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/)
- [LeetCode Editorial (Official)](https://leetcode.com/problems/median-of-two-sorted-arrays/editorial/)
