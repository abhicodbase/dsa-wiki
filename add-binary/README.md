# Add Binary

- **Difficulty:** Easy
- **Categories:** String, Bit Manipulation, Simulation
- **Time Complexity:** $\mathcal{O}(\max(N,M))$
- **Space Complexity:** $\mathcal{O}(1)$ (excluding output string)

---

## Problem Statement

Given two binary strings `a` and `b`, return their sum as a binary string.

Both strings contain only characters `'0'` and `'1'` and may have different lengths.

---

## Constraints

- $1 \le \text{length of } a, b \le 10^4$
- Each character of `a` and `b` is either `'0'` or `'1'`.

---

## Approach

1. Pad the shorter string with leading zeros so both have the same length.
2. Iterate from the least‑significant bit (rightmost) to the most‑significant.
3. Keep a `carry` (0 or 1). For each position compute `sum = (a[i]-'0') + (b[i]-'0') + carry`.
4. The resulting bit is `sum % 2` and the new carry is `sum / 2`.
5. Prepend the resulting bit to the answer string.
6. After processing all positions, prepend a `'1'` if there is a remaining carry.

The algorithm runs in linear time relative to the longer input and uses only constant extra space.

---

## Complexity Analysis

- **Time:** $\mathcal{O}(\max(N, M))$ – a single pass over the longer string.
- **Space:** $\mathcal{O}(1)$ auxiliary (the output string itself is required).

---

## Reference Implementation

```cpp
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        // Pad the shorter string with leading zeros
        if (a.size() < b.size()) a.insert(0, b.size() - a.size(), '0');
        else if (b.size() < a.size()) b.insert(0, a.size() - b.size(), '0');
        string result;
        for (int i = a.size() - 1; i >= 0; --i) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 2;
            result.insert(result.begin(), (sum % 2) + '0');
        }
        if (carry) result.insert(result.begin(), '1');
        return result;
    }
};
```

The full source file is available at [`add_binary.cpp`](file:///Users/abhishekkumar/.gemini/antigravity/scratch/coding/dsa-wiki/add-binary/add_binary.cpp).

---

## Learn More

- [LeetCode – Add Binary](https://leetcode.com/problems/add-binary/)
- [GeeksforGeeks – Add two binary strings](https://www.geeksforgeeks.org/add-two-binary-strings/)
