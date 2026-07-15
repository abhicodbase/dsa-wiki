/*
 * LeetCode #205 — Isomorphic Strings
 * https://leetcode.com/problems/isomorphic-strings/
 *
 * APPROACH: Bidirectional Mapping
 * ──────────────────────────────────────────────────────────────
 * Establish a one-to-one (bijective) mapping between characters of string s
 * and string t. Two strings are isomorphic if the characters in s can be 
 * replaced to get t. We must ensure no character maps to multiple different 
 * characters, and no two different characters map to the same character.
 *
 * TIME  : O(N) — One linear pass over the strings of length N.
 * SPACE : O(1) — Storage is bounded by the character set size (ASCII size of 256).
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Determines if two strings s and t are isomorphic.
     * 
     * @param s The first input string.
     * @param t The second input string.
     * @return True if t can be formed from s by replacing characters, false otherwise.
     */
    bool isIsomorphic(string s, string t) {
        // Fast-exit: strings of different lengths can never be isomorphic
        // (avoids unnecessary map allocation or iteration)
        if (s.length() != t.length()) {
            return false;
        }

        // mp1 maps s[i] -> t[i], mp2 maps t[i] -> s[i]
        // Two maps are required to ensure a strict one-to-one bidirectional mapping
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        
        int len = s.length();
        for (int i = 0; i < len; i++) {
            char char_s = s[i];
            char char_t = t[i];

            // Check if char_s has already been mapped to something other than char_t
            if (mp1.count(char_s) && mp1[char_s] != char_t) {
                return false;
            }

            // Check if char_t has already been mapped to something other than char_s
            // (prevents many-to-one mapping, e.g., 'a' -> 'x' and 'b' -> 'x')
            if (mp2.count(char_t) && mp2[char_t] != char_s) {
                return false;
            }

            // Establish the bidirectional relationship
            mp1[char_s] = char_t;
            mp2[char_t] = char_s;
        }

        return true;
    }
};

/*
 * ALTERNATIVE: First-Occurrence Index Mapping
 * ─────────────────────────────────────────
 * Instead of maintaining character-to-character maps, record the first 
 * position where each character is seen in both strings. If at any position 
 * the first-occurrence indices do not match, the strings are not isomorphic.
 *
 *   bool isIsomorphic(string s, string t) {
 *       int map_s[256] = {0}, map_t[256] = {0};
 *       for (int i = 0; i < s.length(); ++i) {
 *           if (map_s[s[i]] != map_t[t[i]]) return false;
 *           map_s[s[i]] = i + 1; // 1-based indexing to distinguish from default 0
 *           map_t[t[i]] = i + 1;
 *       }
 *       return true;
 *   }
 *
 * Trade-off vs current approach: Uses a single pair of fixed-size arrays (256 integers) 
 * which is faster and uses less memory than dynamic hash maps (unordered_map).
 *
 * UNICODE / FOLLOW-UP EXTENSION:
 * ──────────────────────────────
 * For ASCII inputs, a simple 256-size array (like `int map_s[256]`) can be used for absolute 
 * constant time operations. For Unicode inputs or very large character sets, `unordered_map`
 * must be used to dynamically allocate storage only for present characters.
 */
