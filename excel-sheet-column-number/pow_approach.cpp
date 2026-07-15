/*
 * LeetCode #171 — Excel Sheet Column Number (Power-based Base-26 Conversion)
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.length();
        int sum = 0;
        for(int i = 0; i < len; i++) {
            // For characters before the last position, multiply by the appropriate power of 26.
            if(i != len - 1) {
                sum += (pow(26, (len - i - 1)) * ((columnTitle[i] - 'A') + 1));
            } else {
                // For the last character, simply add its base-26 digit value.
                sum += ((columnTitle[i] - 'A') + 1);
            }
        }
        return sum;
    }
};
