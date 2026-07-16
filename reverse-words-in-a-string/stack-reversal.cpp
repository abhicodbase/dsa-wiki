/*
 * LeetCode #151 — Reverse Words in a String
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * APPROACH: Stack-Based Reversal
 * ──────────────────────────────────────────────────────────────
 * Parse the input string character-by-character to extract words while skipping
 * redundant whitespaces. Pushing extracted words onto a stack naturally reverses 
 * their order. Finally, pop the words from the stack one-by-one and join them 
 * with a single space.
 *
 * TIME  : O(N) — One pass to extract words and another pass to rebuild the string.
 * SPACE : O(N) — Storing words in the stack requires memory proportional to the string size.
 */

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * Reverses the order of words in a string.
     * 
     * @param s The input string containing words separated by spaces.
     * @return The string with words reversed in order and separated by a single space, 
     *         with all leading/trailing and duplicate spaces removed.
     */
    string reverseWords(string s) {
        stack<string> stk;
        string str = "";
        
        // Extract words from the string, ignoring extra spaces
        int len = s.length();
        for (int i = 0; i < len; i++) {
            // Skip leading spaces or duplicate spaces between words
            if (str.empty() && s[i] == ' ') {
                continue;
            }
            // Word boundary encountered: push the completed word to the stack
            if (!str.empty() && s[i] == ' ') {
                stk.push(str);
                str = "";
                continue;
            }
            // Append non-space characters to build the current word
            str += s[i];
        }
        
        // Push the last word if it wasn't followed by a space
        if (!str.empty()) {
            stk.push(str);
        }
        
        string result = "";
        // Reconstruct the string by popping words from the stack (LIFO order)
        while (!stk.empty()) {
            string tp = stk.top();
            
            // Build the result string: avoid prepending a space to the first word
            if (result.empty()) {
                result += tp;
            } else {
                result += ' ' + tp;
            }
            stk.pop();
        }
        
        return result;
    }
};

/*
 * ALTERNATIVE: In-Place Two-Pointer Reversal
 * ─────────────────────────────────────────
 * 1. Reverse the entire string.
 * 2. Reverse each word within the reversed string.
 * 3. Clean up extra spaces by shifting characters using a two-pointer write index.
 *
 *   string reverseWords(string s) {
 *       // Step 1: Reverse the entire string
 *       reverse(s.begin(), s.end());
 *       
 *       int n = s.length();
 *       int writeIdx = 0;
 *       
 *       for (int i = 0; i < n; i++) {
 *           if (s[i] != ' ') {
 *               // Add a single space between words if we're not at the start
 *               if (writeIdx != 0) s[writeIdx++] = ' ';
 *               
 *               // Go to the end of the current word
 *               int start = writeIdx;
 *               while (i < n && s[i] != ' ') {
 *                   s[writeIdx++] = s[i++];
 *               }
 *               
 *               // Step 2 & 3: Reverse the current word in-place
 *               reverse(s.begin() + start, s.begin() + writeIdx);
 *           }
 *       }
 *       s.erase(s.begin() + writeIdx, s.end());
 *       return s;
 *   }
 *
 * Trade-off vs current approach: The in-place approach uses O(1) auxiliary space 
 * (modifying the input string in-place) compared to the stack approach which uses O(N) 
 * auxiliary space.
 *
 * EDGE CASE / CONSTRAINT EXTENSION:
 * ─────────────────────────────────
 * Under severe memory limits, the stack solution can trigger Out-Of-Memory (OOM) 
 * for very large strings (e.g., gigabyte-sized logs). In such scenarios, the in-place 
 * two-pointer approach is mandatory because it processes the data directly in the buffer.
 */
