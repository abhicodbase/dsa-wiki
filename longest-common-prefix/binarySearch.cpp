#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * Helper function to check if all strings in the array share the 
     * same prefix of a given length 'len'.
     */
    bool isCommonPrefix(vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);
        for(int i = 1; i < strs.size(); i++) {
            if(prefix != strs[i].substr(0, len)) {
                return false;
            }
        }
        return true;
    }

    /**
     * Performs a binary search to find the maximum valid length of the common prefix.
     */
    int getPrefixLength(vector<string>& strs, string str) {
        int low = 0, high = str.length();
        int result = 0;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isCommonPrefix(strs, mid)) {
                result = mid;    // mid is valid, store it as a potential result
                low = mid + 1;   // Try to find a longer common prefix
            } else {
                high = mid - 1;  // Try a shorter prefix
            }
        }
        return result;
    }

    /**
     * Finds the longest common prefix among an array of strings using Binary Search.
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        int minLen = INT_MAX;
        // ✅ Find MINIMUM length among all strings
        // The common prefix cannot be longer than the shortest string.
        for(int i = 0; i < strs.size(); i++) {
            minLen = min(minLen, (int)strs[i].length());
        }
        
        // Binary search for the prefix length bounded by minLen
        int len = getPrefixLength(strs, strs[0].substr(0, minLen));
        return strs[0].substr(0, len);
    }
};