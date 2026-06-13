# Counting Bits

**LeetCode #338** · [LeetCode](https://leetcode.com/problems/counting-bits/) · [NeetCode](https://neetcode.io/problems/counting-bits)

- **Difficulty:** Easy
- **Categories:** Dynamic Programming, Bit Manipulation
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

---

## Problem Statement

Given an integer `n`, return an array `ans` of length `n + 1` such that `ans[i]` is the number of `1`s in the binary representation of `i`, for every `0 <= i <= n`.

**Examples:**
```
Input: n = 2    →  Output: [0, 1, 1]
  0 = 000 → 0 ones
  1 = 001 → 1 one
  2 = 010 → 1 one

Input: n = 5    →  Output: [0, 1, 1, 2, 1, 2]
  3 = 011 → 2 ones
  4 = 100 → 1 one
  5 = 101 → 2 ones
```

---

## Intuition

Every integer `i` in binary is just `i/2` (right-shifted by 1) with the least significant bit (LSB) possibly appended:

```
i = 5  →  101   →  i/2 = 2  →  10   (drop LSB 1)
i = 6  →  110   →  i/2 = 3  →  11   (drop LSB 0)
i = 7  →  111   →  i/2 = 3  →  11   (drop LSB 1)
```

So: **`popcount(i) = popcount(i/2) + (i % 2)`**

Since we're computing answers for 0 → n in order, `popcount(i/2)` is always already in the table when we need it. Each entry costs O(1) — no bit-counting loop needed.

---

## Approach: DP with Last-Bit Extraction

```
v[0] = 0                          (base case)
v[i] = v[i / 2] + (i % 2)        for i = 1..n
```

| i | binary | i/2 | i%2 | v[i] |
|---|--------|-----|-----|------|
| 0 | 000    | —   | —   | 0    |
| 1 | 001    | 0   | 1   | 0+1=1|
| 2 | 010    | 1   | 0   | 1+0=1|
| 3 | 011    | 1   | 1   | 1+1=2|
| 4 | 100    | 2   | 0   | 1+0=1|
| 5 | 101    | 2   | 1   | 1+1=2|

---

## Code

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n + 1, 0);   // v[0] = 0 (base case)

        for (int i = 1; i <= n; i++) {
            int bit     = i % 2;   // LSB: 1 if odd, 0 if even
            int prevRes = i / 2;   // i with LSB dropped → already computed
            v[i] = v[prevRes] + bit;
        }

        return v;
    }
};
```

Equivalent one-liner using bitwise operators (`>>` and `&`):

```cpp
v[i] = v[i >> 1] + (i & 1);
//       ^^^^^^        ^^^
//      i / 2         i % 2
```

Both forms are identical — the compiler generates the same code either way.

---

## Complexity

|           | Value | Reason |
|-----------|-------|--------|
| **Time**  | O(n)  | Single pass; O(1) work per index |
| **Space** | O(n)  | Output array only — no extra structures |

---

## Edge Cases

| Input | Output | Note |
|-------|--------|------|
| `n = 0` | `[0]` | Only 0, which has no 1-bits |
| `n = 1` | `[0, 1]` | 1 = `1` in binary |
| Power of 2 (e.g. `n = 4`) | `..., 1` at index 4 | Powers of 2 always have exactly one 1-bit |

---

## Files

| File | Description |
|------|-------------|
| [`dp-last-bit.cpp`](./dp-last-bit.cpp) | C++ DP solution using last-bit extraction |

---

## Related Problems

- [LC #191 — Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) — count bits for a single number; building block for this problem
- [LC #136 — Single Number](https://leetcode.com/problems/single-number/) — bit manipulation with XOR
- [LC #201 — Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/) — range-level bit reasoning
