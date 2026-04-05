#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> memo;

  bool isPalindrome(const string &s, int i, int j) {
    if (i >= j)
      return true;
    if (memo[i][j] != -1)
      return memo[i][j];

    if (s[i] == s[j]) {
      return memo[i][j] = isPalindrome(s, i + 1, j - 1);
    }
    return memo[i][j] = 0;
  }

public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1)
      return s;

    memo.assign(n, vector<int>(n, -1));

    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (isPalindrome(s, i, j)) {
          if (j - i + 1 > maxLen) {
            maxLen = j - i + 1;
            start = i;
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
