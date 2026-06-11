/*
 * LeetCode #242 — Valid Anagram
 * https://leetcode.com/problems/valid-anagram/
 *
 * APPROACH: Dual character frequency arrays
 * ──────────────────────────────────────────
 * Two strings are anagrams if and only if they contain exactly the same
 * characters with exactly the same frequencies.
 *
 * We use two fixed-size arrays of length 26 (one per lowercase letter a–z)
 * to record how many times each character appears in s and t respectively,
 * then compare them position by position.
 *
 * TIME  : O(N)  — three linear passes over s, t, and the 26-element arrays
 * SPACE : O(1)  — always exactly 2 × 26 = 52 integers, independent of input
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Fast-exit: different lengths can never be anagrams
        // (saves iterating through both arrays when sizes differ)
        if (s.length() != t.length()) return false;

        // Frequency tables for lowercase letters 'a'–'z'
        // Index 0 = 'a', index 1 = 'b', …, index 25 = 'z'
        // Both initialised to zero via the second argument of the constructor
        vector<int> st(26, 0);
        vector<int> tt(26, 0);

        // Count character frequencies for s
        // s[i] - 'a' maps character to index: 'a'→0, 'b'→1, …, 'z'→25
        for (int i = 0; i < (int)s.length(); i++)
            st[s[i] - 'a']++;

        // Count character frequencies for t
        for (int i = 0; i < (int)t.length(); i++)
            tt[t[i] - 'a']++;

        // Compare both frequency tables element by element
        // If every count matches, s and t are anagrams of each other
        for (int i = 0; i < 26; i++) {
            if (st[i] != tt[i]) return false; // mismatch found — not an anagram
        }

        return true; // all 26 character counts match → valid anagram
    }
};

/*
 * ALTERNATIVE (single-array approach):
 * ─────────────────────────────────────
 * Use one array: increment for s, decrement for t.
 * Return true if all entries are 0 after both passes.
 *
 *   vector<int> freq(26, 0);
 *   for (char c : s) freq[c - 'a']++;
 *   for (char c : t) freq[c - 'a']--;
 *   for (int f : freq) if (f != 0) return false;
 *   return true;
 *
 * Same time/space complexity; slightly more compact.
 *
 * UNICODE NOTE:
 * ─────────────
 * This approach only works for lowercase English letters (a–z).
 * For Unicode strings, use an unordered_map<char, int> instead of
 * a fixed-size array, which changes space to O(k) where k is the
 * number of distinct characters.
 */
