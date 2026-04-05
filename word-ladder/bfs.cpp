#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
      return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
      string word = q.front().first;
      int steps = q.front().second;
      q.pop();

      if (word == endWord)
        return steps;

      for (int i = 0; i < word.length(); ++i) {
        char original = word[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          if (c == original)
            continue;
          word[i] = c;
          if (dict.count(word)) {
            q.push({word, steps + 1});
            dict.erase(word);
          }
        }
        word[i] = original;
      }
    }

    return 0;
  }
};

int main() {
  Solution sol;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << "Input: hit -> cog | Output: "
       << sol.ladderLength(beginWord, endWord, wordList) << endl;

  vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
  cout << "Input: hit -> cog (not in list) | Output: "
       << sol.ladderLength(beginWord, endWord, wordList2) << endl;

  return 0;
}
