// LeetCode 338 — Counting Bits
// Approach: DP with last-bit extraction
//
// Key insight:
//   Right-shifting i by 1 (i/2) drops the least significant bit.
//   So popcount(i) = popcount(i/2) + (i % 2).
//   We already know popcount(i/2) from a previous result — pure O(1) per index.
//
// Equivalent formulation: v[i] = v[i >> 1] + (i & 1)
//   i >> 1  == i / 2  (right shift = integer division by 2)
//   i & 1   == i % 2  (AND with 1 = last bit)
//
// Time:  O(n) — single pass, O(1) work per index
// Space: O(n) — output array (no extra space beyond the result)

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
