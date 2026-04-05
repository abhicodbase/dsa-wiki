#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1)
      return s;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;
    int start = 0;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        start = i;
        maxLen = 2;
      }
    }

    // Check for lengths greater than 2
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i < n - len + 1; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          if (len > maxLen) {
            start = i;
            maxLen = len;
          }
        }
      }
    }

    return s.substr(start, maxLen);
  }
};

int main() {
  Solution sol;
  string s1 = "babad";
  string s2 = "cbbd";
  string s3 = "a";
  string s4 = "ac";

  cout << "Input: " << s1 << " | Output: " << sol.longestPalindrome(s1) << endl;
  cout << "Input: " << s2 << " | Output: " << sol.longestPalindrome(s2) << endl;
  cout << "Input: " << s3 << " | Output: " << sol.longestPalindrome(s3) << endl;
  cout << "Input: " << s4 << " | Output: " << sol.longestPalindrome(s4) << endl;

  return 0;
}
