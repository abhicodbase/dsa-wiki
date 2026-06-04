# Boats to Save People

- **Difficulty:** Medium
- **Categories:** Array, Two Pointers, Greedy, Sorting
- **Time Complexity:** $\mathcal{O}(N \log N)$
- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(\log N)$ (for sorting space)

---

## Problem Statement

You are given an array `people` where `people[i]` is the weight of the $i$-th person, and an infinite number of boats where each boat can carry a maximum weight of `limit`. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most `limit`.

Return *the minimum number of boats to carry every given person*.

---

### Examples

**Example 1:**
- **Input:** `people = [1,2]`, `limit = 3`
- **Output:** `1`
- **Explanation:** 1 boat is needed to carry both people since `1 + 2 = 3` (which is $\le$ limit).

**Example 2:**
- **Input:** `people = [3,2,2,1]`, `limit = 3`
- **Output:** `3`
- **Explanation:** 3 boats are needed:
  - Boat 1: `[1, 2]`
  - Boat 2: `[2]`
  - Boat 3: `[3]`

**Example 3:**
- **Input:** `people = [3,5,3,4]`, `limit = 5`
- **Output:** `4`
- **Explanation:** 4 boats are needed:
  - Boat 1: `[3]`
  - Boat 2: `[3]`
  - Boat 3: `[4]`
  - Boat 4: `[5]`

---

### Constraints

- $1 \le \text{people.length} \le 5 \cdot 10^4$
- $1 \le \text{people}[i] \le \text{limit} \le 3 \cdot 10^4$

---

## Approach: Two Pointer Greedy on Sorted Array

To minimize the total number of rescue boats, we must maximize the number of boats carrying **two** people:
1. **Sort the array**: Sorting the weights allows us to easily find the lightest and heaviest remaining people.
2. **Pair Lightest and Heaviest**: Use two pointers, `left` (lightest) and `right` (heaviest).
   - If `people[left] + people[right] <= limit`, then both can fit in one boat. We advance `left` and decrement `right`.
   - If they exceed the limit, the heaviest person `people[right]` cannot possibly fit in a boat with anyone else (since `people[left]` is the lightest). Hence, the heaviest person must take a boat alone. We decrement `right`.
   - In both cases, a boat is used, so we increment our boat count.

### Algorithm Flow

```mermaid
graph TD
    Start([Start]) --> Sort[Sort people array]
    Sort --> Init[Initialize left = 0, right = size - 1, count = 0]
    Init --> Loop{left <= right?}
    
    Loop -- Yes --> Match{people[left] + people[right] <= limit?}
    Match -- Yes --> Pair[Pair: left++, right--]
    Match -- No --> Alone[Heaviest Alone: right--]
    
    Pair --> Increment[count++]
    Alone --> Increment
    Increment --> Loop
    
    Loop -- No --> End([Return count])
```

See implementation in [greedy.cpp](file:///Users/abhishekkumar/.gemini/antigravity/scratch/coding/dsa-wiki/boats-to-save-people/greedy.cpp).

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N)$
  - Sorting the `people` array of size $N$ takes $\mathcal{O}(N \log N)$ time.
  - The two-pointer traversal takes $\mathcal{O}(N)$ since each person is processed at most once.
  - Therefore, the overall time complexity is dominated by the sorting step: $\mathcal{O}(N \log N)$.

- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(\log N)$
  - If sorting is done in place, the auxiliary space complexity is $\mathcal{O}(1)$.
  - Stack space required by the sorting algorithm (e.g. `std::sort` quicksort) is $\mathcal{O}(\log N)$.

---

## Learn More

- [LeetCode #881 - Boats to Save People](https://leetcode.com/problems/boats-to-save-people/)
- [NeetCode - Boats to Save People](https://neetcode.io/problems/boats-to-save-people)
