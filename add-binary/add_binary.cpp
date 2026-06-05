#include <string>
#include <algorithm>

using namespace std;

/**
 * Class Solution provides a method to add two binary strings.
 * The algorithm pads the shorter string with leading zeros, then
 * iterates from the least‑significant bit to the most‑significant,
 * computing the sum and carry at each position.
 * Time Complexity: O(n) where n is max(al, bl).
 * Space Complexity: O(n) for the result string.
 */
class Solution {
public:
    /**
     * Adds two binary numbers represented as strings.
     * @param a First binary string.
     * @param b Second binary string.
     * @return Binary sum as a string.
     */
    string addBinary(string a, string b) {
        int carry = 0;
        int al = a.length();
        int bl = b.length();
        // Pad the shorter string with leading zeros so both have equal length.
        if (al < bl) {
            a.insert(0, bl - al, '0');
        } else if (bl < al) {
            b.insert(0, al - bl, '0');
        }
        int binaryLength = a.length();
        string result = "";
        // Process bits from right to left.
        while (binaryLength > 0) {
            int sum = (a[binaryLength - 1] - '0') + (b[binaryLength - 1] - '0') + carry;
            carry = sum / 2;                 // New carry.
            char current = (sum % 2) + '0';   // Result bit.
            result = current + result;        // Prepend to result.
            binaryLength--;
        }
        // If a carry remains after the most‑significant bit, prepend it.
        if (carry) {
            result = '1' + result;
        }
        return result;
    }
};
