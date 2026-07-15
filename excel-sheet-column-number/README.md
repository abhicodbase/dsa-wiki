# Excel Sheet Column Number

- **Difficulty:** Easy
- **Categories:** Math, String

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Power-based Evaluation** | $O(N)$ | $O(1)$ | Uses `std::pow(26, exponent)` to evaluate the base-26 value at each index. |
| **Accumulative Evaluation** | $O(N)$ | $O(1)$ | Optimal. Accumulates values from left to right, avoiding floating-point `pow` calls. |

---

Given a string `columnTitle` that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:
```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
```

**Examples:**
```
Input:  columnTitle = "A"   → Output: 1
Input:  columnTitle = "AB"  → Output: 28
Input:  columnTitle = "ZY"  → Output: 701
```

---

## Approach 1: Positional Powers

1. We can treat the string as a base-26 number where `'A'` is $1$, `'B'` is $2$, ..., and `'Z'` is $26$.
2. For each character at index `i` (from left to right):
   - The value is calculated as: `(columnTitle[i] - 'A' + 1) * pow(26, len - i - 1)`.
   - The last character (index `len - 1`) has an exponent of `0`, so we simply add its face value.

---

## Approach 2: Accumulative Evaluation (Optimal)

Instead of using `pow` which introduces floating-point operations and function call overhead, we can process characters left-to-right using **Horner's method** for polynomial evaluation:
1. Initialize `sum = 0`.
2. For each character `c` in `columnTitle`:
   - Multiply the running `sum` by 26 to shift all previously processed digits one place value to the left.
   - Add the digit value of the current character: `(c - 'A' + 1)`.
   - For example:
     - `"AB"` $\to$ First char `'A'`: `sum = 0 * 26 + 1 = 1`.
     - Second char `'B'`: `sum = 1 * 26 + 2 = 28`.

This runs in linear time and uses integer multiplication, which is faster and cleaner.

---

## Files

| File | Description |
| :--- | :--- |
| [`pow_approach.cpp`](./pow_approach.cpp) | C++ solution using `std::pow` for positional power additions |
| [`optimal.cpp`](./optimal.cpp) | Optimal C++ solution evaluating the polynomial accumulatively |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/excel-sheet-column-number)
- [LeetCode](https://leetcode.com/problems/excel-sheet-column-number/)
