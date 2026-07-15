/*
 * LeetCode #171 — Excel Sheet Column Number (Accumulative Base-26 Conversion)
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (char c : columnTitle) {
            // Shift the current sum by multiplying by base 26, then add the value of the current digit.
            // This is Horner's method for polynomial evaluation and avoids the overhead of calling pow().
            // We use 'c - 'A' + 1' since 'A' represents 1, 'B' represents 2, ..., 'Z' represents 26.
            sum = sum * 26 + (c - 'A' + 1);
        }
        return sum;
    }
};
