#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Helper function to check if a substring is a palindrome.
 *
 * Logic:
 * - Base Case: If start exceeds or equals end, we've validated the entire
 * substring.
 * - Recursive Step: Compare the characters at `start` and `end`. If they match,
 *   check the inner substring (start + 1, end - 1).
 *
 * @param str The input string.
 * @param start Starting index of the substring.
 * @param end Ending index of the substring.
 * @return true if the substring is a palindrome, false otherwise.
 */
bool isPalindrome(const string &str, int start, int end) {
  if (start >= end)
    return true;
  return (str[start] == str[end] && isPalindrome(str, start + 1, end - 1));
}

/**
 * @brief Recursively explores all substrings to find the longest palindrome.
 *
 * This function uses a "top-down" recursive approach:
 * 1. Checks if the current range [start, end] forms a palindrome.
 * 2. If it does, updates the maximum length found so far (`*mx`).
 * 3. Recursively branches to check substrings by excluding the character at
 *    the left (`start + 1`) and the right (`end - 1`).
 *
 * @note This implementation has exponential time complexity O(2^n) because it
 *       recalculates many overlapping substrings.
 *
 * @param str The input string.
 * @param start Current starting index.
 * @param end Current ending index.
 * @param mx Pointer to the variable storing the maximum length found.
 */
void longestPalindromeSubStr(const string &str, int start, int end, int *mx) {
  // Base Case: Stop if the range becomes invalid
  if (start > end)
    return;

  // Check if the current substring [start, end] is a palindrome
  // We update 'mx' if a longer palindrome is found.
  if (isPalindrome(str, start, end)) {
    *mx = max(*mx, end - start + 1);
  }

  // Branching: Explore smaller substrings by shrinking the range from both ends
  longestPalindromeSubStr(str, start + 1, end, mx);
  longestPalindromeSubStr(str, start, end - 1, mx);
}

int main() {
  string str = "abba";
  int mx = 0;

  if (!str.empty()) {
    // Initial call with the full range of the string
    longestPalindromeSubStr(str, 0, str.length() - 1, &mx);
  }

  cout << "longest substring Palindrome length " << mx << "\n";
  return 0;
}