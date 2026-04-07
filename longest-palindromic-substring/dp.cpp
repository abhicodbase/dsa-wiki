#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to find the longest palindromic substring
string longestPalindrome(string s) {
  int len = s.length(); // Length of the input string
  int mx = 1;           // Stores maximum palindrome length (at least 1)
  int startIndex = 0;   // Starting index of longest palindrome found

  // DP table where dp[i][j] = true means substring s[i..j] is palindrome
  vector<vector<bool>> dp(len, vector<bool>(len, false));

  // Base case 1: All single characters are palindrome
  for (int i = 0; i < len; i++) {
    dp[i][i] = true;
  }

  // Base case 2: Check for substrings of length 2
  for (int i = 0; i < len - 1; i++) {
    if (s[i] == s[i + 1]) { // If both characters are same
      dp[i][i + 1] = true;  // Mark as palindrome

      // Update max length and starting index if needed
      if (mx < 2) {
        mx = 2;
        startIndex = i;
      }
    }
  }

  // For substrings of length >= 3
  // diff represents the gap between i and j (j - i)
  for (int diff = 2; diff < len; diff++) {
    for (int j = diff; j < len; j++) {
      int i = j - diff; // Calculate starting index

      // A substring is palindrome if:
      // 1. Inner substring dp[i+1][j-1] is palindrome
      // 2. Characters at both ends are equal
      dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];

      // If current substring is palindrome and longer than previous max
      if (dp[i][j] && mx < j - i + 1) {
        startIndex = i; // Update starting index
        mx = j - i + 1; // Update max length
      }
    }
  }

  // Return the longest palindromic substring
  return s.substr(startIndex, mx);
}

int main() {
  string str = "abab"; // Input string

  cout << "Input: " << str << endl;

  // Call function and print result
  cout << "Longest Palindromic Substring: " << longestPalindrome(str) << endl;

  return 0;
}