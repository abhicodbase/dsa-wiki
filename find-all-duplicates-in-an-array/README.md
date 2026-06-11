# Find All Duplicates in an Array

**LeetCode #442** · [LeetCode](https://leetcode.com/problems/find-all-duplicates-in-an-array/) · [NeetCode](https://neetcode.io/problems/find-all-duplicates-in-an-array)

- **Difficulty:** Medium
- **Categories:** Array, Hash Table
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

## Problem Statement

Given an integer array `nums` of length `n` where each integer is in the range `[1, n]` and each integer appears **once or twice**, return an array of all integers that appear **twice**.

You must write an algorithm that runs in O(N) time and uses **O(1) extra space**.

**Examples:**
```
Input:  nums = [4, 3, 2, 7, 8, 2, 3, 1]  →  Output: [2, 3]
Input:  nums = [1, 1, 2]                  →  Output: [1]
Input:  nums = [1]                        →  Output: []
```

---

## Intuition

Every value in `nums` is in range `[1, n]`, so every value maps to a valid index: `value v → index (v − 1)`. We can exploit this to use the **array itself as a hash map** — no extra data structure needed.

The trick is to use the **sign of `nums[v-1]`** as a single-bit "visited" flag for the value `v`:
- **First visit** to value `v` → negate `nums[v-1]` (mark it visited)
- **Second visit** to value `v` → `nums[v-1]` is already negative → double negation makes it positive → `v` is a duplicate

This is called the **in-place negation** (or index-as-hash) technique. It works whenever values are bounded by array size — a common pattern in interview problems.

---

## Approach: Index as Hash (In-place Negation)

For each element at position `i`:
1. Take `x = abs(nums[i])` to recover the original value (may already be negated)
2. Go to the "marker slot" at index `x − 1`
3. Negate `nums[x-1]` to mark `x` as seen
4. If after negating `nums[x-1] > 0`, the value was already negative — this is `x`'s **second visit** → duplicate

```cpp
for (int i = 0; i < n; i++) {
    int x = abs(nums[i]);         // recover original value (ignoring prior negations)
    nums[x - 1] = -nums[x - 1];  // flip sign at marker index → "visited" flag

    // Two flips = back to positive = seen twice = duplicate
    if (nums[x - 1] > 0) result.push_back(x);
}
```

### Step-by-step trace — `nums = [4, 3, 2, 7, 8, 2, 3, 1]`

| Step | x | Action | nums[x-1] after | Duplicate? |
|------|---|--------|-----------------|------------|
| i=0 | 4 | negate nums[3]: 7 → -7  | -7  | No  |
| i=1 | 3 | negate nums[2]: 2 → -2  | -2  | No  |
| i=2 | 2 | negate nums[1]: 3 → -3  | -3  | No  |
| i=3 | 7 | negate nums[6]: 3 → -3  | -3  | No  |
| i=4 | 8 | negate nums[7]: 1 → -1  | -1  | No  |
| i=5 | 2 | negate nums[1]: -3 → **+3** | +3 | **Yes → 2** |
| i=6 | 3 | negate nums[2]: -2 → **+2** | +2 | **Yes → 3** |
| i=7 | 1 | negate nums[0]: 4 → -4  | -4  | No  |

**Result: `[2, 3]`** ✓

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time** | O(N) | Single pass over all `n` elements; constant work per element |
| **Space** | O(1) | No extra data structures; sign flips happen in the input array itself |

> Output vector is not counted as extra space (it holds only the answer).

---

## Alternative Approach: HashSet

When you **cannot mutate** the input array, use an `unordered_set` to track seen values:

```cpp
unordered_set<int> seen;
vector<int> result;
for (int num : nums) {
    if (!seen.insert(num).second)  // insert() returns false if already present
        result.push_back(num);
}
return result;
```

| | Negation trick | HashSet |
|---|---|---|
| **Time** | O(N) | O(N) |
| **Space** | **O(1)** | O(N) |
| Mutates input? | Yes | No |
| Simpler code? | No | Yes |

**Use HashSet** when the input array is read-only or mutation is forbidden.

---

## Edge Cases

| Scenario | Result |
|---|---|
| No duplicates (`[1, 2, 3, 4]`) | `[]` — empty result |
| All duplicates (`[2, 1, 2, 1]`) | `[2, 1]` |
| Single element (`[1]`) | `[]` |
| All same value (`[2, 2]`) | `[2]` |
| Max-size n=1000 with all pairs | All n/2 values returned |

---

## Files

| File | Description |
|---|---|
| [`index-negation.cpp`](./index-negation.cpp) | In-place negation C++ solution with full inline comments, trace walkthrough, and alternative approach |

---

## Related Problems

- [Find the Duplicate Number (LC #287)](https://leetcode.com/problems/find-the-duplicate-number/) — Same constraint (values in [1,n]); Floyd's cycle detection for O(1) space
- [Find All Numbers Disappeared in an Array (LC #448)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) — Same negation technique; find missing values instead of duplicates
- [First Missing Positive (LC #41)](https://leetcode.com/problems/first-missing-positive/) — Index-as-hash approach with cyclic sort variant
- [Set Mismatch (LC #645)](https://leetcode.com/problems/set-mismatch/) — Combines finding one duplicate and one missing value
